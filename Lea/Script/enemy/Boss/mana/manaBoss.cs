using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using static UnityEngine.GraphicsBuffer;

public class manaBoss : MonoBehaviour
{
    //보스 스크립트
    public GameObject Bullet;
    public BoxCollider2D collider;

    float pattern_delay;

    float Damage;

    float DamageTextxPos;

    public static int HP;

    Vector2 playerpos;

    public GameObject damegeText;
    float angle;



    void Start()
    {
        collider = GetComponent<BoxCollider2D>();
        collider.enabled = false;
        pattern_delay = 5;
        StartCoroutine(Startattct());
        HP = gamedata.bossEnemyHpData;
    }

    IEnumerator Startattct()
    {
        yield return new WaitForSeconds(6);
        collider.enabled = true;
        StartCoroutine(Boss_Skill());
    }

    IEnumerator Boss_Skill()
    {
        Instantiatebullet();
        yield return new WaitForSeconds(pattern_delay);
        StartCoroutine(Boss_Skill());
    }

    void Update()
    {
        death();
    }
    private float GetAngle(Vector3 end, Vector3 start)
    {
        Vector2 v2 = end - start;
        return Mathf.Atan2(v2.y,v2.x) * Mathf.Rad2Deg;
    }
    //총알 생성
    void Instantiatebullet()
    {
        playerpos = GameObject.Find("player").transform.position;
        var tmp =  Instantiate(Bullet, transform.position, Quaternion.identity);
        angle = GetAngle(playerpos, tmp.transform.position);
        tmp.transform.rotation = Quaternion.Euler(new Vector3(0,0,angle - 90));

    }
    //데미지 체크
    private void OnCollisionEnter2D(Collision2D collision)
    {
        DamageTextxPos = Random.Range(-0.25f, 0.25f);
        if (collision.gameObject.tag == "mana")
        {
            Damage = gamedata.PlayerDamagData + gamedata.manaMagicDamege;
            HP -= (int)Damage;
            Instantiate(damegeText, new Vector3(transform.position.x + DamageTextxPos,transform.position.y+2), Quaternion.identity).GetComponent<PrintDamage>().Init(Damage);
        }
        if(collision.gameObject.tag == "fire")
        {
            Damage = gamedata.PlayerDamagData + gamedata.fireMagicDamege;
            HP -= (int)Damage;
            Instantiate(damegeText, new Vector3(transform.position.x + DamageTextxPos, transform.position.y + 2), Quaternion.identity).GetComponent<PrintDamage>().Init(Damage);
        }
        if (collision.gameObject.tag == "electro")
        {
            Damage = gamedata.PlayerDamagData + gamedata.electroMagicDamege;
            HP -= (int)Damage;
            Instantiate(damegeText, new Vector3(transform.position.x + DamageTextxPos, transform.position.y + 2), Quaternion.identity).GetComponent<PrintDamage>().Init(Damage);
        }
    }

    void death()
    {
        if(HP <= 0)
        {
            SceneManager.LoadScene("Credit");
            //gameObject.SetActive(false);
            Destroy(gameObject);
        }
    }



}
