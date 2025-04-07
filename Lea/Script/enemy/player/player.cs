using System.Collections;
using System.Collections.Generic;
using UnityEditor.Rendering;
using UnityEngine;
using data;
using Unity.VisualScripting;


public class player : MonoBehaviour
{
    public GameObject setting;
    //�÷��̾� ��ũ��Ʈ
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
    //Ű �Է�
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

    //�ִϸ��̼�
    void animetion(){
        if (rd.velocity.x == 0 && rd.velocity.y == 0){
            ai.SetBool("run", false );
        }
        else{
            ai.SetBool("run",true);
        }
    }
    //ä�¼���
    void Playerhpset(){

        Hp = PlayerHp;

        //max���� ũ�� max�� ����
        if (PlayerHp > gamedata.PlayerHpMaxBaseData)
        {
            PlayerHp = gamedata.PlayerHpMaxBaseData;
            Hp = PlayerHp;
        }
        //����
        if (Hp <= 0){
            Gameover();
        }
    }
    //������ �ޱ�
    void OnCollisionEnter2D(Collision2D collision)
    {
        if(collision.gameObject.tag == "enemy" && canhit == false)
        {
            canhit = true;
            PlayerHp -= gamedata.enemydamage;
            StartCoroutine(HitDelay());
        }
    }
    //������ �޾����� ���� ������
    IEnumerator HitDelay()
    {
        yield return new WaitForSeconds(hitdelay);
        canhit = false;
    }

    //���ӿ���
    void Gameover(){
        GameManager.Instance.gameover();
    }
}
