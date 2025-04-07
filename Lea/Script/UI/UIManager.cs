using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.UIElements;

public class UIManager : MonoBehaviour
{
    //설정창
    public GameObject setting;
    //설명창
    public GameObject Help;



    public SoundManager SoundManager;

    private void Start()
    {
        if (setting != null)
        {
            setting.SetActive(false);
        }
        if (Help != null)
        {
            Help.SetActive(false);
        }
    }


    public void SettingOn()
    {
        if(setting != null)
        {
            setting.SetActive(true);
        }
        
    }

    public void SettingOff()
    {
        if (setting != null)
        {
            setting.SetActive(false);
        }
    }

    public void HelpOn()
    {
        if(Help != null)
        {
            Help.SetActive(true);
        }
    }

    public void HelpOff()
    {
        if (Help != null)
        {
            Help.SetActive(false);
        }
    }
}
