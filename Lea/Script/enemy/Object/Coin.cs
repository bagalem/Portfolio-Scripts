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
            // 현재 위치에서 타겟 위치까지의 방향을 계산합니다.
            Vector2 direction = (Vector2)player.position - rd.position;
            direction.Normalize();

            // 속도를 설정하여 이동합니다.
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
