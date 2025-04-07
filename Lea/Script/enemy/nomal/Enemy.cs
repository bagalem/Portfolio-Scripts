using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    //모든 적에게 적용되는 부모 클래스
    //적 기본코드
    public float moveSpeed;
    public int Hp;
    public int damage;
    public bool canelectr = true;
    public float canelectrtime;
    float Damage;
    float DamageTextxPos;
    public GameObject coin;

    public GameObject Enemyparticle;

    public GameObject damegeText;
    public GameObject target;

    public virtual void Start()
    {
        Hp = gamedata.littelEnemyHpData;
        canelectrtime = 1f;
        moveSpeed = gamedata.EnemyspeedData;
        target = GameObject.Find("player");
    }
    public virtual void Update()
    {

    }
    //데미지 체크
    public virtual void OnCollisionEnter2D(Collision2D other)
    {
        if (other.gameObject.tag == "mana")
        {
            Hp -= gamedata.PlayerDamagData + gamedata.manaMagicDamege;
        }
        if (other.gameObject.tag == "fire")
        {
            Hp -= gamedata.PlayerDamagData + gamedata.fireMagicDamege;
        }
        //데미지 텍스트 띄우기
        DamageTextxPos = Random.Range(-0.25f, 0.25f);
        if (other.gameObject.tag == "mana")
        {
            Damage = gamedata.PlayerDamagData + gamedata.manaMagicDamege;
            Instantiate(damegeText, new Vector3(transform.position.x + DamageTextxPos, transform.position.y + 2), Quaternion.identity).GetComponent<PrintDamage>().Init(Damage);
        }
        if (other.gameObject.tag == "fire")
        {
            Damage = gamedata.PlayerDamagData + gamedata.fireMagicDamege;
            Instantiate(damegeText, new Vector3(transform.position.x + DamageTextxPos, transform.position.y + 2), Quaternion.identity).GetComponent<PrintDamage>().Init(Damage);
        }
        

        if (Hp <= 0)
        {
            dropCoin();
            particle();
            Destroy(gameObject);
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {

        if (collision.gameObject.tag == "electro")
        {
            Hp -= gamedata.PlayerDamagData + gamedata.electroMagicDamege;
        }
        if (collision.gameObject.tag == "electro")
        {
            Damage = gamedata.PlayerDamagData + gamedata.electroMagicDamege;
            Instantiate(damegeText, new Vector3(transform.position.x + DamageTextxPos, transform.position.y + 2), Quaternion.identity).GetComponent<PrintDamage>().Init(Damage);
        }

        if (Hp <= 0)
        {
            dropCoin();
            particle();
            Destroy(gameObject);
        }
    }

    void dropCoin()
    {
        Instantiate(coin,new Vector2 (transform.position.x,transform.position.y),Quaternion.identity);
    }

    void particle()
    {
        Destroy(Instantiate(Enemyparticle,new Vector2(transform.position.x,transform.position.y),Quaternion.identity), 3f);
    }


}
