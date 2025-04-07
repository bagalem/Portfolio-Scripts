using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Soul : MonoBehaviour
{
    Vector2 angle;
    Rigidbody2D rd;

    public GameObject player;
    bool isEndDelay;

    void Start()
    {
        isEndDelay = true;
        rd = GetComponent<Rigidbody2D>();
        StartCoroutine(Animetion());
    }

    IEnumerator Animetion()
    {
        angle.x = Random.Range(0, 5f);
        angle.y = Random.Range(0, 5f);

        rd.velocity = angle;
        yield return new WaitForSeconds(0.2f);
        isEndDelay = false;

    }
    void FixedUpdate()
    {
        player = GameObject.Find("Player");
        if (isEndDelay && player != null)
        {
            // ���� ��ġ���� Ÿ�� ��ġ������ ������ ����մϴ�.
            Vector2 direction = (Vector2)player.transform.position - rd.position;
            direction.Normalize();

            // �ӵ��� �����Ͽ� �̵��մϴ�.
            rd.velocity = direction * 30;
        }
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            player = GameObject.Find("Player");
            player.gameObject.GetComponent<Player>().Soul++;
            Destroy(gameObject);
        }
    }

    void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            player = GameObject.Find("Player");
            player.gameObject.GetComponent<Player>().Soul++;
            Destroy(gameObject);
        }
    }

}
