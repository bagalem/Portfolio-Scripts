using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class stats : MonoBehaviour
{
    public int typenumber;

    public statsCoin coin;
    public statsLV LV;

    // Update is called once per frame
    void Update()
    {
        if (typenumber == 0)
        {
            coin.SetCoin(gamedata.Stats0BuyCoin);
            
            LV.SetLV(gamedata.stats0LV, typenumber);
        }
        if (typenumber == 1)
        {
            coin.SetCoin(gamedata.Stats1BuyCoin);
            LV.SetLV(gamedata.stats1LV, typenumber);
        }
        if (typenumber == 2)
        {
            coin.SetCoin(gamedata.Stats2BuyCoin);
            LV.SetLV(gamedata.stats2LV, typenumber);
        }
    }

    public void buy()
    {
        if (typenumber == 0)
        {
            if (gamedata.coin > gamedata.Stats0BuyCoin && gamedata.stats0LV < 14)
            {
                gamedata.coin -= gamedata.Stats0BuyCoin;
                gamedata.Stats0BuyCoin += 50;
                gamedata.stats0LV++;
                gamedata.MagicShootDelayData -= 0.05f;
            }
        }
        else
        {

        }

        if (typenumber == 1)
        {
            if (gamedata.coin > gamedata.Stats1BuyCoin)
            {
                gamedata.coin -= gamedata.Stats1BuyCoin;
                gamedata.Stats1BuyCoin += 50;
                gamedata.stats1LV++;
                gamedata.PlayerDamagData++;
            }
        }
        else
        {

        }

        if (typenumber == 2)
        {
            if (gamedata.coin > gamedata.Stats2BuyCoin)
            {
                gamedata.coin -= gamedata.Stats2BuyCoin;
                gamedata.Stats2BuyCoin += 50;
                gamedata.stats2LV++;
                gamedata.PlayerHpMaxBaseData++;
            }
        }
        else
        {

        }


    }
}
