using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerfallowcam : MonoBehaviour
{
    public Transform player;
    //ī�޶� �÷��̾ ������� �ڵ�
    void Update(){
        transform.position = new Vector3(player.transform.position.x, player.transform.position.y,-10);
    }
}
