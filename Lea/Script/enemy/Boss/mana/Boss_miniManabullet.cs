using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Boss_miniManabullet : MonoBehaviour
{
    //큰 탄환에서 나온 작은탄환 스크립트
    public float Speed;

    public float DelayTime;
    Rigidbody2D rd;
    void Start()
    {
        DelayTime = 5;
        Speed = 8;
        rd = GetComponent<Rigidbody2D>();
        StartCoroutine(ObjectLiveTime());
    }
    void Update()
    {
        rd.velocity = transform.up * Speed;
    }
    //총알이 살이있는 시간
    IEnumerator ObjectLiveTime()
    {
        yield return new WaitForSeconds(DelayTime);
        Destroy(gameObject);
    }
    //삭제
    private void OnCollisionEnter2D(Collision2D other)
    {
        Destroy(gameObject);
    }
}
