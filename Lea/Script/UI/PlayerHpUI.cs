using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerHpUI : MonoBehaviour
{
    player Player;
    public Slider hp;
    void Start()
    {
        Player = GetComponent<player>();
        hp.maxValue = gamedata.PlayerHpMaxBaseData;
        hp.value = Player.Hp;
    }

    // Update is called once per frame
    void Update()
    {
        hp.maxValue = gamedata.PlayerHpMaxBaseData;
        hp.value = Player.Hp;
    }
}
