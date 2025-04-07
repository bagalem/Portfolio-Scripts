using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using data;
public class middelenemy : Enemy
{
    //�Ѿ��� ��� �� (�Ƹ� ��� ��������)
    public float shootdelay;
    public GameObject enemybullet;
    Vector2 target2;
    float angle;

    public override void Start(){
        target = GameObject.Find("player");
        base.Start();
        shootdelay = gamedata.EnemyShootDelay;
        StartCoroutine(shoot());
    }

    IEnumerator shoot(){
        Instantiatebullet();
        yield return new WaitForSeconds(shootdelay);
        StartCoroutine(shoot());
    }

    void Instantiatebullet(){
   	    angle = Mathf.Atan2(target.transform.position.y - target2.y, target.transform.position.x - target2.x) * Mathf.Rad2Deg;

        Instantiate(enemybullet,new Vector3(transform.position.x,transform.position.y,transform.position.z)
        ,Quaternion.AngleAxis(angle, Vector3.forward));
    }
}
