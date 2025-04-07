using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UIElements;

public class TitleButtenAnimetion : MonoBehaviour, IPointerEnterHandler, IPointerExitHandler
{
    //UI 에니메이션
    Transform scale;
    public float size;
    RectTransform Rtransform;
    public float speed;

    public void OnPointerEnter(PointerEventData eventData)
    {
        scale.localScale = new Vector2(transform.localScale.x + size, transform.localScale.y + size);
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        scale.localScale = new Vector2(transform.localScale.x - size, transform.localScale.y - size);
    }

    IEnumerator Start()
    {
        Rtransform = GetComponent<RectTransform>();
        scale = GetComponent<Transform>();
        for (float i = 0; i < 1; i+= Time.deltaTime / speed)
        {
            float a = Rtransform.anchoredPosition.x;
            Rtransform.anchoredPosition = Vector2.Lerp(new Vector2(a, Rtransform.anchoredPosition.y), Vector2.up * Rtransform.anchoredPosition.y,i);
            yield return null;
        }
    }
}
