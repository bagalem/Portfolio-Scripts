using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEngine.GraphicsBuffer;

public class Coin : MonoBehaviour
{
    [SerializeField] private bool isEndDelay;
    [SerializeField] private float Speed = 50f;


    public Transform player;

    private Rigidbody2D rd;
    void Start()
    {
        rd = GetComponent<Rigidbody2D>();
        isEndDelay = false;
        StartCoroutine(StayDelay());
    }
    private void FixedUpdate()
    {
        player = GameObject.Find("player").GetComponent<Transform>();
        if (isEndDelay && player != null)
        {
            // ���� ��ġ���� Ÿ�� ��ġ������ ������ ����մϴ�.
            Vector2 direction = (Vector2)player.position - rd.position;
            direction.Normalize();

            // �ӵ��� �����Ͽ� �̵��մϴ�.
            rd.velocity = direction * Speed;
        }

        if(GameManager.Instance.RoomNumber != (int)gamedata.map.battelMap)
        {
            Destroy(gameObject);
        }
    }

    IEnumerator StayDelay()
    {
        yield return new WaitForSeconds(3);
        isEndDelay = true;
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            gamedata.coin += 5 + (GameManager.Instance.nowfloor);
            SoundManager.Instance.PlayEffectSound(3);
            Destroy(gameObject);
        }
    }
}
