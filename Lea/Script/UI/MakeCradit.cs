using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MakeCradit : MonoBehaviour
{
    public GameObject Cradit;

    private void Start()
    {
        Cradit.SetActive(false);
    }
    public void MakeCreditOn()
    {
        Cradit.SetActive(true);
    }

    public void MakeCraditDff()
    {
        Cradit.SetActive(false);
    }
}
