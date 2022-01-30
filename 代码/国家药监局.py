import requests
import json
if __name__ =="__main__":
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.198 Safari/537.36'
    }
    url = "http://scxk.nmpa.gov.cn:81/xk/itownet/portalAction.do?method=getXkzsList"
    id_list = []
    for page in range(1,6):
        page = str(page)
        data = {
            'on': 'true',
            'page':page,
            'pageSize': '15',
            'productName':'',
            'conditionType': '1',
            'applyname':'',
            'applysn':'',
        }
        json_ids = requests.post(url=url,data=data,headers=headers).json()
        for dic in json_ids['list']:
            id_list.append(dic['ID'])
    #print(id_list)
    all_data_list = []
    post_url = "http://scxk.nmpa.gov.cn:81/xk/itownet/portalAction.do?method=getXkzsById"
    for id in id_list:
        data ={
            'id':id
        }
        detail_json = requests.post(url=post_url,data=data,headers=headers).json()
        #print(detail_json,'------ending------')
        all_data_list.append(detail_json)
    fp = open('./国家药监局.html','w',encoding='utf-8')
    json.dump(all_data_list,fp=fp,ensure_ascii=False)
    print("over!!!")