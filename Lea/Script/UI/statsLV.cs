using data;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class statsLV : MonoBehaviour
{
    int Typenum;
    private int LV;
    TMP_Text text;
    // Start is called before the first frame update
    void Start()
    {
        text = GetComponent<TMP_Text>();
    }

    // Update is called once per frame
    void Update()
    {
        
        if (LV >= 14 && Typenum == 0)
        {
            text.text = "LV:Max";
        }
        else
        {
            text.text = "LV:" + LV;
        }
    }

    public void SetLV(int value,int typenum)
    {
        LV = value;
        Typenum = typenum;
    }
}
