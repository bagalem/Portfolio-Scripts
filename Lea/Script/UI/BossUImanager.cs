using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;

public class BossUImanager : MonoBehaviour
{
    public CanvasGroup BossName;
    public CanvasGroup Bossbar;
    
    void OnEnable()
    {
        StartCoroutine(BossUIEffect());
    }

    IEnumerator BossUIEffect()
    {
        BossName.alpha = 0;
        Bossbar.alpha = 0;

        for (int i = 0; i < 100; i++)
        {
            BossName.alpha += 0.01f;
            yield return null;
        }
        yield return new WaitForSeconds(2f);
        for (float i = 100;i > 0; i--)
        {
            BossName.alpha -= 0.01f;
            yield return null;
        }

        Bossbar.alpha = 1;
    }
}
