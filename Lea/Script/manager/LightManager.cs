using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Rendering.Universal;

public class LightManager : MonoBehaviour
{

    //URP빛 조절 하는 스크립트
    public GameObject GlobalLight2D;
    Light2D light2D;

    private void Start()
    {
        light2D = GlobalLight2D.GetComponent<Light2D>();
        LightSetting(0.2f);
    }

    private void Update()
    {
        LightChange();
    }

    void LightSetting(float GlobalLightValue)
    {
        light2D.intensity = GlobalLightValue;
    }

    void LightChange()
    {
        if (GameManager.Instance.RoomNumber == (int)gamedata.map.battelMap)
        {
            LightSetting(0.6f);
        }
        if(GameManager.Instance.RoomNumber == (int)gamedata.map.mainMap)
        {
            LightSetting(0.3f); 
        }
        if(GameManager.Instance.RoomNumber == (int)gamedata.map.bossMap)
        {
            LightSetting(0.55f);
        }
        if (GameManager.Instance.RoomNumber == (int)gamedata.map.shelterMap)
        {
            LightSetting(0.6f);
        }
    }
}
