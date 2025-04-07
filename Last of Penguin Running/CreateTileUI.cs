using LopRunning.ObjectTile;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CreateTileUI : MonoBehaviour
{
    //TODO : 타일의 갯수를 동적으로 수정할수 있게 수정

    #region Scroll
    [Header("스크롤")]
    //BackGround 스크롤
    public GameObject TileSlotScroll;
    //Object 스크롤
    public GameObject ObjectSlotScroll;
    //Monster 스크롤
    public GameObject MonsterSlotScroll;
    //Jelly 스크롤
    public GameObject JellySlotScroll;
    #endregion
    #region content
    [Header("컨텐츠")]
    //BackGround 컨텐츠
    public Transform TileContent;
    //Object 컨텐츠
    public Transform ObjectContent;
    //Monster 컨텐츠
    public Transform MonsterContent;
    //Jelly 컨텐츠
    public Transform JellyContent;
    #endregion
    [Header("그 외")]
    //캔버스가 2개여서 MainUI캔버스로 지정해줘야한다.
    public GameObject Canvas;
    //타일위나 아래에 설치해야 된다는 설명이 적혀있는 프리펩
    public ObjectList Get_Object;

    //슬롯 중 컨텐츠 안에 있는 오브젝트 기본 프리펩
    public GameObject Slot_PreFab;

    public GameObject ObjectExplanation;

    [Header("리스트업")]
    [SerializeField]
    public List<GameObject> TileList;
    [SerializeField]
    public List<GameObject> ObjectList;
    [SerializeField]
    public List<GameObject> JellyList;
    [SerializeField]
    public List<GameObject> MonsterList;

    void Start()
    {
        TileList = EditorUIButtonManager.Instence.GetTileList();
        ObjectList = EditorUIButtonManager.Instence.GetObjectList();
        JellyList = EditorUIButtonManager.Instence.GetJellyList();
        MonsterList = EditorUIButtonManager.Instence.GetMonsterList();

        #region 타일 리스트업
        int number = 0;

        for (int i = 1; i < Get_Object.objects.Length; i++)
        {
            Transform[] Content = { TileContent, ObjectContent, JellyContent, MonsterContent };
            List<GameObject>[] List = { TileList, ObjectList, JellyList, MonsterList };
            GameObject[] Scroll = { TileSlotScroll, TileSlotScroll, JellySlotScroll, MonsterSlotScroll };



            bool IsJelly = false;
            bool addexplanation = false;

            if (i > 1 && i < 14)
            {
                number = 0;

                IsJelly = false;
                addexplanation = false;
            }
            else if (i > 14 && i < 29)
            {
                number = 1;

                if (i < 27)
                {
                    IsJelly = false;
                    addexplanation = true;
                }
                else
                {
                    IsJelly = false;
                    addexplanation = false;
                }
            }
            else if (i > 29 && i < 39)
            {
                number = 2;

                IsJelly = true;
                addexplanation = false;
            }
            else if (i > 39 && i < Get_Object.objects.Length - 2)
            {
                number = 3;

                IsJelly = false;
                addexplanation = false;
            }




            //타일을 만들때 들어가는 UI 인덱스 번호 수정

            if (Get_Object.objects[i] != null)
            {
                if (number == 2)
                {
                    MakeSlot(i - 29, Get_Object.objects[i].GetComponent<SpriteRenderer>().sprite, Content[number], List[number], IsJelly, addexplanation);
                }
                else if (number == 3)
                {
                    MakeSlot(i - 10, Get_Object.objects[i].GetComponent<SpriteRenderer>().sprite, Content[number], List[number], IsJelly, addexplanation);
                }
                else
                {
                    MakeSlot(i, Get_Object.objects[i].GetComponent<SpriteRenderer>().sprite, Content[number], List[number], IsJelly, addexplanation);
                }

            }

            if (i % 12 == 0)
            {
                Content[number].GetComponent<RectTransform>().sizeDelta = new Vector2(Content[number].GetComponent<RectTransform>().sizeDelta.x + Scroll[number].GetComponent<RectTransform>().sizeDelta.x - 30, Content[number].GetComponent<RectTransform>().sizeDelta.y);
            }
        }
        #endregion
    }

    void MakeSlot(int Index, Sprite GetSprit, Transform Parent, List<GameObject> list, bool isjelly, bool addexplanation)
    {
        //i:for문에 i, INdex:오브젝트의 인덱스 번호,Parent부모 content,GetList:가지고올 리스트list: 슬롯이 들어가야할 리스트

        //슬롯에 타일 UI를 만드는 함수
        var obj = Instantiate(Slot_PreFab);

        obj.GetComponent<TileUI>().changeNumber(Index, isjelly);
        obj.GetComponent<UnityEngine.UI.Image>().sprite = GetSprit;

        obj.GetComponent<TileUI>().SetExplanation(ObjectExplanation);

        if (addexplanation)
        {
            obj.GetComponent<TileUI>().SetUseDescriptions(addexplanation);
            obj.GetComponent<TileUI>().SetCanvas(Canvas);
        }
        else
        {
            obj.GetComponent<TileUI>().SetUseDescriptions(addexplanation);
        }

        list.Add(obj);
        obj.transform.SetParent(Parent, false);

    }
}
