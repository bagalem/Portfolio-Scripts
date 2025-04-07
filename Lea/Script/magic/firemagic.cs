using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class firemagic : MonoBehaviour
{
    // 불 마법 스크립트
    public float Speed = 20f;

    public float DelayTime;
    Rigidbody2D rd;
    void Start(){
        DelayTime = 0.25f;
        rd = GetComponent<Rigidbody2D>();
        StartCoroutine(ObjectLiveTime());
    }
    void Update()
    {
       rd.velocity = transform.up*Speed;
    }

    IEnumerator ObjectLiveTime(){
        yield return new WaitForSeconds(DelayTime);
        Destroy(gameObject);
    }

    private void OnCollisionEnter2D(Collision2D other) {
        Destroy(gameObject);
    }
}
