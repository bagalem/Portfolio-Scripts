using System.Collections;
using System.Collections.Generic;
using data;
using UnityEngine;

public class talkChack : MonoBehaviour
{
    //�̰� ������� �𸣰ڴµ� ��ȭ�Ҷ� �ൿ���߻縦 ��Ȱ��ȭ ��Ű�� �ڵ�
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
