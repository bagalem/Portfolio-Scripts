using System.Collections;
using System.Collections.Generic;
using data;
using JetBrains.Annotations;
using UnityEngine;

namespace magicSp
{
    public class magic : MonoBehaviour
    {
        //플레이어가 쏘는 마법 스크립트
        [SerializeField] int magicnum = gamedata.MagicMumData;
        float angle;
        #region 프리펩
        public GameObject manabulletPf;
        public GameObject FirePf;
        public GameObject electricitymagic;
        public GameObject lightmagic;
        public float delay;
        Vector2 mouse;
        #endregion

        void Start()
        {
            canshoot = true;
            gamedata.MagicMumData = 0;
        }
        //홀드를 체크하는 변수 들이였으나 지금은 사용하지 않음
        public float HoldTime = gamedata.HoldTimeData;
        public float HoldEndTime = gamedata.HoldEndTimeData;
        [SerializeField]
        public bool canshoot = true;

        void Update()
        {
            magicnum = gamedata.MagicMumData;
            if (gamedata.ActionData == false)
            {
                magicshoot();
            }

            magicchange();
        }
        //마법생성
        void magicshoot()
        {
            if (Input.GetMouseButton(0) && canshoot == true)
            {
                if (gamedata.MagicMumData == 0)
                {
                    SoundManager.Instance.PlayEffectSound(2);
                    InstantiateGameobject(manabulletPf);
                }
                if (gamedata.MagicMumData == 1)
                {
                    InstantiateGameobject(FirePf);
                }
                if (gamedata.MagicMumData == 2)
                {
                    //마우스 위치에 시전되게 설정함
                    InstantiateGameobject(electricitymagic);
                    //gamedata.InsEleData = false;
                    //StartCoroutine(shootdelay(delay));
                }

            }
        }

        void magicchange()
        {
            if (Input.GetKeyDown(KeyCode.Alpha1))
            {
                gamedata.MagicMumData = 0;
            }
            if (Input.GetKeyDown(KeyCode.Alpha2))
            {
                gamedata.MagicMumData = 1;
            }
            if (Input.GetKeyDown(KeyCode.Alpha3))
            {
                gamedata.MagicMumData = 2;
            }
        }

        //마우스방향을 바라보게 회전
        void InstantiateGameobject(GameObject obj)
        {
            canshoot = false;
            if (obj.tag == "electro")
            {
                mouse = Camera.main.ScreenToWorldPoint(Input.mousePosition);
                Instantiate(obj, new Vector3(mouse.x, mouse.y,-5), Quaternion.identity);
                
            }
            else
            {
                mouse = Camera.main.ScreenToWorldPoint(Input.mousePosition) - Camera.main.transform.position;
                angle = Mathf.Atan2(mouse.y, mouse.x) * Mathf.Rad2Deg;



                Instantiate(obj, new Vector3(transform.position.x, transform.position.y, transform.position.z)
                , Quaternion.AngleAxis(angle - 90, Vector3.forward));
            }

            delay = gamedata.MagicShootDelayData;

            StartCoroutine(shootdelay(delay));
        }


        //마법 딜레이
        IEnumerator shootdelay(float delay_time)
        {
            yield return new WaitForSeconds(delay_time);
            canshoot = true;
        }

        //홀드를 위한 체크
        IEnumerator holdchack()
        {
            yield return new WaitForSeconds(0.1f);
            HoldTime += 0.1f;
            gamedata.holdfireData = true;
        }
    }
}


