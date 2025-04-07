using System.Collections;
using System.Collections.Generic;
using data;
using UnityEngine;

public class manamagic : MonoBehaviour
{
    //기본 탄환
    public float Speed;

    public float DelayTime = 3;
    Rigidbody2D rd;
    void Start(){
        Speed = gamedata.ManaSpeedData;
        rd = GetComponent<Rigidbody2D>();
        StartCoroutine(ObjectLiveTime());
    }
    void Update()
    {
       rd.velocity = transform.up*Speed;
    }
    //총알이 살이있는 시간
    IEnumerator ObjectLiveTime(){
        yield return new WaitForSeconds(DelayTime);
        Destroy(gameObject);
    }
    //삭제
    private void OnCollisionEnter2D(Collision2D other) {
        Destroy(gameObject);
    }
}
