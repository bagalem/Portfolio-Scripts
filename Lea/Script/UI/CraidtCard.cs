using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CraidtCard : MonoBehaviour
{
    //엔딩 크레딧 카드
    public float speed;
    Rigidbody2D rd;

    void Start()
    {
        speed = 1;
        rd = GetComponent<Rigidbody2D>();
    }
    // Update is called once per frame
    void Update()
    {
        rd.velocity = new Vector2(rd.velocity.x, speed);
        if (Input.GetMouseButton(0))
            speed = 5;
        else
            speed = 1;
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "craditEnd")
        {
            SceneManager.LoadScene("Splash");
        }
    }

}
