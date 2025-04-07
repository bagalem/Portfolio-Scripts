using data;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class statsCoin : MonoBehaviour
{
    private int coin;
    TMP_Text text;
    // Start is called before the first frame update
    void Start()
    {
        text = GetComponent<TMP_Text>();    
    }

    // Update is called once per frame
    void Update()
    {
        if (coin > gamedata.coin)
        {
            text.color = Color.red;
        }
        else
        {
            text.color = Color.black;
        }

        text.text = coin.ToString();
    }

    public void SetCoin(int value)
    {
        coin = value;
    }
}
