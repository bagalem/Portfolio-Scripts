using DG.Tweening;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Logo : MonoBehaviour
{
    public float DelayTime;
    SpriteRenderer sr;
    Color currentColor;

    void Start()
    {
        sr = GetComponent<SpriteRenderer>();
        currentColor = sr.color;
        currentColor.a = 0f;
        sr.color = currentColor;
        StartCoroutine(Fade());
        StartCoroutine(Scale());
    }

    IEnumerator Fade()
    {
        yield return new WaitForSeconds(DelayTime);

        for (float i = 0; i < 100; i++)
        {
            yield return null;
            currentColor = sr.color;
            currentColor.a = i / 100f;
            sr.color = currentColor;
        }
    }
    IEnumerator Scale() { 
        yield return new WaitForSeconds(DelayTime);
        for(float i = 0;i < 100; i++)
        {
            yield return null;
            if (i < 50)
            {
                transform.localScale = new Vector2(1 + (i / 1000), 1 + (i / 1000));
            }
            else
            {
                transform.localScale = new Vector2(1 + (i / 1000), 1 + (i / 1000));
            }
                
        }
        yield return new WaitForSeconds(2f);

    }
}
