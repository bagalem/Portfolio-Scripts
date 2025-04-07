using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Boss_miniManabullet : MonoBehaviour
{
    //ū źȯ���� ���� ����źȯ ��ũ��Ʈ
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
    //�Ѿ��� �����ִ� �ð�
    IEnumerator ObjectLiveTime()
    {
        yield return new WaitForSeconds(DelayTime);
        Destroy(gameObject);
    }
    //����
    private void OnCollisionEnter2D(Collision2D other)
    {
        Destroy(gameObject);
    }
}
