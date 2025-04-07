using data;
using System.Collections.Generic;
using UnityEngine;

public class ShopManager : MonoBehaviour
{
    [SerializeField] bool isbuying;
    public GameObject StatsUI;
    public List<GameObject> Stats;
    public List<Transform> placementpoint;
    bool isAction;
    // Start is called before the first frame update
    void Start()
    {
        StatsUI.SetActive(false);
        SetRandomStats();
    }

    // Update is called once per frame
    void Update()
    {
        isAction = gamedata.ActionData;

        SetActiveObject();

        if (StatsUI && Input.GetKey(KeyCode.P))
        {
            gamedata.coin += 1000;
        }
    }

    void SetRandomStats()
    {
        int num = 0;
        for (int i = 0; i < placementpoint.Count; i++)
        {
            //int type = Random.Range(0, Stats.Count);
            //if (num == type)
            //{
            //    continue;
            //}
            //else
            //{
            //    num = type;
            //    var obj =  Instantiate(Stats[type], new Vector2(placementpoint[i].transform.position.x, placementpoint[i].transform.position.y), Quaternion.identity);
            //    obj.transform.SetParent(StatsUI.transform);
            //}
            var obj = Instantiate(Stats[i], new Vector2(placementpoint[i].transform.position.x, placementpoint[i].transform.position.y), Quaternion.identity);
            obj.transform.SetParent(StatsUI.transform);
        }

    }

    public void Exit()
    {
        StatsUI.SetActive(false);
        gamedata.ActionData = false;
    }

    void SetActiveObject()
    {
        if (isAction == true)
        {
            if (StatsUI.activeSelf == false)
            {
                StatsUI.SetActive(true);
            }
        }
        else if (isAction == false)
        {
            if (StatsUI.activeSelf == true)
            {
                StatsUI.SetActive(false);
            }
        }
    }
}
