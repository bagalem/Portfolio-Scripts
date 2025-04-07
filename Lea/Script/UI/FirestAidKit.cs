using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FirestAidKit : MonoBehaviour
{
    public GameObject part;
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            player.PlayerHp += 5 + GameManager.Instance.nowfloor;
            Destroy(Instantiate(part, new Vector3(transform.position.x, transform.position.y,-3), Quaternion.identity),1);
            StartCoroutine(liveDelay());
            gameObject.SetActive(false);
            

        }
    }

    IEnumerator liveDelay()
    {
        yield return new WaitForSeconds(30f);
        gameObject.SetActive(true);
    }
}
