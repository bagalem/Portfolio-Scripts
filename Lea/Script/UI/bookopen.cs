using System.Collections;
using System.Collections.Generic;
using data;
using UnityEngine;

public class bookopen : MonoBehaviour
{
    //å UI ��ũ��Ʈ
    public GameObject book;

    public void BookOpen(){
        if (data.gamedata.canbookpoenData == true){
            book.gameObject.SetActive(true);
            data.gamedata.canbookpoenData = false;
        }
    }

    public void BookClose(){
        if (data.gamedata.canbookpoenData == false){
            book.gameObject.SetActive(false);
            data.gamedata.canbookpoenData = true;
        }
    }
}
