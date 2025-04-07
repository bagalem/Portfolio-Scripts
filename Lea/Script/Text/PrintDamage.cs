using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;

public class PrintDamage : MonoBehaviour
{
    public void Init(float damage)
    {
        transform.GetComponent<TMP_Text>().text = $"-{damage}";
        StartCoroutine(Textani());
    }

    IEnumerator Textani()
    {
        yield return new WaitForSeconds(1);
        Destroy(gameObject);
    }
}
