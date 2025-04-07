using System.Collections;
using System.Collections.Generic;
using data;
using UnityEngine;

public class SpawnManager : MonoBehaviour
{
    //���� �����ϴ� �����ʿ� �� �ִ� ��ũ��Ʈ
    public GameObject enemy0,enemy1,enemy2;
    [SerializeField]
    bool spawning;
    
    
    void Start(){
        gamedata.Active = false;
        spawning = false;
    }
    void Update()
    {
        if(GameManager.Instance.EnemySpawnIndex > GameManager.Instance.EndEnemySpawnIndex)
        {
            spawning = false;
            gamedata.Active = false;
        }
            

        if (GameManager.Instance.RoomNumber == (int)gamedata.map.battelMap && GameManager.Instance.EnemySpawnIndex < GameManager.Instance.EndEnemySpawnIndex)
        {
            gamedata.Active = true;
        }
        else
        {
            gamedata.Active = false;
            spawning = false;
        }
               
        
        if (gamedata.Active && !spawning)
        {
            StartCoroutine(spawn());
            spawning = true;
        }

        if(GameManager.Instance.RoomNumber != (int)gamedata.map.battelMap)
        {
            gamedata.Active = false;
            spawning = false;
        }
    }
    //�����ڵ�
    IEnumerator spawn(){
        Instantiate(enemy0, new Vector3(transform.position.x,transform.position.y,-3),Quaternion.identity);
        GameManager.Instance.EnemySpawnIndex++;
        yield return new WaitForSeconds(gamedata.EnemySpwanDelayData);
        if (gamedata.Active)
            StartCoroutine(spawn());
    }

}
