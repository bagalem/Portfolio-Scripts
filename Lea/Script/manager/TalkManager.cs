using System.Collections;
using System.Collections.Generic;
using data;
using UnityEngine;
using TMPro;
using UnityEngine.UI;

public class TalkManager : MonoBehaviour
{
    //��ȭ
    //���� ��ȭ�� �� �� ����Ʈ
    [SerializeField] private List<string> talkdata = new List<string>();
    public GameObject talkBackground,textobj;
    TMP_Text text;
    public int i = 0;
    public bool isAction;
    void Start(){
        text = textobj.GetComponent<TMP_Text>();
        conversationdata();
        Debug.Log(talkdata.Count);
        
    }

    // Update is called once per frame
    void Update()
    {
        
        isAction = gamedata.ActionData;
        
        SetActiveObject();

        if (Input.GetKeyDown(KeyCode.Space)){
            i++;
            if (i >= talkdata.Count){
                i = 0;
                gamedata.ActionData = false;
            }
        }
        text.text = talkdata[i].ToString();

        
        
    }
    //��ȭ�� �� �� �߰�
    void conversationdata(){
        talkdata.Add("text 1");
        talkdata.Add("text 2");
        talkdata.Add("text 3");
        talkdata.Add("text 4");
        talkdata.Add("text 5");
        talkdata.Add("text 6");
        talkdata.Add("text 7");
        talkdata.Add("text 8");
    }
    //��ȭâ Ȱ��ȭ/��Ȱ��ȭ
    void SetActiveObject(){
        if (isAction == true){
            if (talkBackground.activeSelf == false){
                talkBackground.SetActive(true);
            }
            if (textobj.activeSelf == false){
                textobj.SetActive(true);
            } 
        }
        else if(isAction == false) {
            if(talkBackground.activeSelf == true){
                talkBackground.SetActive(false);
            }
            if (textobj.activeSelf == true){
                textobj.SetActive(false);
            }
        }
    }
    
}
