using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class textmanager : MonoBehaviour
{
    public TMP_Text floorText;

    // Update is called once per frame
    void Update()
    {
        floortext();
    }

    void floortext()
    {
        floorText.text = GameManager.Instance.nowfloor.ToString() + " F";
    }
}
