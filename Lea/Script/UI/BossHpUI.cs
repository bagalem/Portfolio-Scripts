using data;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class BossHpUI : MonoBehaviour
{
    //보스 체력 UI 셋팅
    public Slider BossSlider;
    public manaBoss boss;

    private void Start()
    {
        boss = GetComponent<manaBoss>();
        SetMaxHp(gamedata.bossEnemyHpData);
    }

    void Update()
    {
        SetHp(manaBoss.HP);
    }

    public void SetMaxHp(int Hp)
    {
        BossSlider.maxValue = Hp;
        BossSlider.value = Hp;
    }

    public void SetHp(int Hp)
    {
        BossSlider.value = Hp;
        if(Hp > gamedata.bossEnemyHpData)
        {
            BossSlider.value = gamedata.bossEnemyHpData;
        }
    }

}
