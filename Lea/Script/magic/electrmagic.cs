using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using data;

public class electrmagic : MonoBehaviour
{
    //���� ���� ��ũ��Ʈ
    void Start()
    {
        StartCoroutine(end());
    }
    IEnumerator end()
    {
        yield return new WaitForSeconds(0.7f);
        Destroy(gameObject);
    }

}