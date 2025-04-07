using System.Collections;
using System.Collections.Generic;
using UnityEditor.Rendering;
using UnityEngine;
using data;
using Unity.VisualScripting;


public class player : MonoBehaviour
{
    public GameObject setting;
    //플레이어 스크립트
    public static int PlayerHp;
    public int Hp;
    Rigidbody2D rd;
    SpriteRenderer sr;
    Animator ai;
    float hitdelay = 1.5f;
    bool canhit;
    
    
    public float speed = gamedata.PlayerSpeedData;


    // Start is called before the first frame update
    void Start()
    {
        canhit = false;
        PlayerHp = gamedata.PlayerHpMaxBaseData;


        ai = GetComponent<Animator>();
        rd = GetComponent<Rigidbody2D>();
        sr = GetComponent<SpriteRenderer>();
    }

    
    void Update()
    {
        if (gamedata.ActionData == false){
            PlayerKeycheck();
        }

        animetion();

        Playerhpset();

        if (setting.gameObject.activeSelf == true)
            Time.timeScale = 0;
        else if (setting.gameObject.activeSelf == false)
            Time.timeScale = 1;

    }
    //키 입력
    private void PlayerKeycheck()
    {
        if (Input.GetKey(KeyCode.W)){
            rd.velocity = new Vector2(rd.velocity.x,speed);
        }
        else if (Input.GetKey(KeyCode.S)){
            rd.velocity = new Vector2(rd.velocity.x, -speed);
        }
        else{
            rd.velocity = new Vector2(rd.velocity.x,0);
        }

        if (Input.GetKey(KeyCode.D)){
            rd.velocity = new Vector2(speed,rd.velocity.y);
            sr.flipX = true;
        }
        else if (Input.GetKey(KeyCode.A)){
            rd.velocity = new Vector2(-speed, rd.velocity.y);
            sr.flipX = false;
        }
        else{
            rd.velocity = new Vector2(0,rd.velocity.y);
        }

        if (Input.GetKeyDown(KeyCode.Escape))
        {
            setting.SetActive(true);
        }
    }

    //애니메이션
    void animetion(){
        if (rd.velocity.x == 0 && rd.velocity.y == 0){
            ai.SetBool("run", false );
        }
        else{
            ai.SetBool("run",true);
        }
    }
    //채력셋팅
    void Playerhpset(){

        Hp = PlayerHp;

        //max보가 크면 max로 셋팅
        if (PlayerHp > gamedata.PlayerHpMaxBaseData)
        {
            PlayerHp = gamedata.PlayerHpMaxBaseData;
            Hp = PlayerHp;
        }
        //죽음
        if (Hp <= 0){
            Gameover();
        }
    }
    //데미지 받기
    void OnCollisionEnter2D(Collision2D collision)
    {
        if(collision.gameObject.tag == "enemy" && canhit == false)
        {
            canhit = true;
            PlayerHp -= gamedata.enemydamage;
            StartCoroutine(HitDelay());
        }
    }
    //데미지 받았을때 무적 딜레이
    IEnumerator HitDelay()
    {
        yield return new WaitForSeconds(hitdelay);
        canhit = false;
    }

    //게임오버
    void Gameover(){
        GameManager.Instance.gameover();
    }
}
