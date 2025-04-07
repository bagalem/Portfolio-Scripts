using System.Collections;
using System.Collections.Generic;
using data;
using UnityEngine;

public class talkChack : MonoBehaviour
{
    //이걸 썼는지는 모르겠는데 대화할때 행동과발사를 비활성화 시키는 코드
    bool collide = false;
    void Update(){
        if(collide){
            if (gamedata.ActionData == false){
                if (Input.GetKeyDown(KeyCode.F)){
                    gamedata.ActionData = true;
                }
            }
        }
    }
    void OnTriggerEnter2D(Collider2D other) {
        if (other.gameObject.tag == "Shop")
        {
            collide = true;
        }
        
    }
    void OnTriggerExit2D(Collider2D other) {
        if (other.gameObject.tag == "Shop")
        {
            collide = false;
        }
    }
}
