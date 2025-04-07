using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using data;
using magicSp;

public class Option : MonoBehaviour
{
    public magic mg;
    public void OnStap()
    {
        Time.timeScale = 0;
        mg.canshoot = false;
    }

    public void Onclase()
    {
        Time.timeScale = 1;
        mg.canshoot = true;
    }
}
