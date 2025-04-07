using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEngine.GraphicsBuffer;

public class Boss_ManaBullet : MonoBehaviour
{
    //보스가 탄환을 발사하고 그 탄환이 분열되는 코드
    public GameObject miniBullet;
    public float speed;
    public float live_Time;
    Rigidbody2D rd;

    float angle;

    void Start(){
        angle = 0;
        speed = 1f;
        live_Time = 10f;
        rd = GetComponent<Rigidbody2D>();
        StartCoroutine(NextAct());
    }
    void Update()
    {
        rd.velocity = transform.up * speed;
    }

    IEnumerator NextAct()
    {
        yield return new WaitForSeconds(live_Time);
        for (int i = 0; i < 5; i++)
        {
            Instantiatebullet();
        }
        Destroy(gameObject);
    }

    void Instantiatebullet()
    {
        angle = Random.Range(0, 360);

        Instantiate(miniBullet, new Vector3(transform.position.x, transform.position.y, transform.position.z)
        , Quaternion.AngleAxis(angle - 90, Vector3.forward));
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(gameObject);
    }
}
