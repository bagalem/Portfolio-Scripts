using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class TextManager : MonoBehaviour
{

    public TMP_Text floorText;
    // Start is called before the first frame update
    void Start()
    {
        SetfloorText();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void SetfloorText()
    {
        floorText.text = GameManager.Instance.nowfloor.ToString();

        if (GameManager.Instance.nowfloor <= 5)
        {
            Color color;
            ColorUtility.TryParseHtmlString("#0080FF", out color);

            floorText.color = color; 
        }
        else if(GameManager.Instance.nowfloor < 5 && GameManager.Instance.nowfloor <= 10)
        {
            Color color;
            ColorUtility.TryParseHtmlString("#FF3A00", out color);

            floorText.color = color;

        }
        else if(GameManager.Instance.nowfloor < 10 && GameManager.Instance.nowfloor <= 15)
        {

        }
        else if(GameManager.Instance.nowfloor < 15 && GameManager.Instance.nowfloor <= 20)
        {
            floorText.color = Color.white;
        }
    }
}
