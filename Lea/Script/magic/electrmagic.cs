using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using data;

public class electrmagic : MonoBehaviour
{
    //전기 마법 스크립트
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