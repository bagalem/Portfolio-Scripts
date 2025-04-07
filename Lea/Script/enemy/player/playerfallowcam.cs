using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerfallowcam : MonoBehaviour
{
    public Transform player;
    //카메라가 플레이어를 따라오는 코드
    void Update(){
        transform.position = new Vector3(player.transform.position.x, player.transform.position.y,-10);
    }
}
