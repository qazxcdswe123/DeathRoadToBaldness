import json
import requests


def get_download_url(apiKey, modID, gameVersion):
    # example URL https://api.curseforge.com/v1/mods/{{modID}}/files?gameVersion=1.19
    base_url = "https://api.curseforge.com/"
    url = base_url + "v1/mods/" + modID + "/files?gameVersion=" + gameVersion
    response = requests.get(url, headers={'x-api-key': apiKey})
    if response.status_code == 200:
        data = json.loads(response.text)
        for item in data['data']:
            download_url = item['downloadUrl']
            file_name = item['fileName']

            # find stable release
            if item['releaseType'] == 1:
                return download_url, file_name
    else:
        print("Error: " + response.status_code)
        return None


def saveFile(file_name, url):
    response = requests.get(url)
    if response.status_code == 200:
        with open(file_name, 'wb') as f:
            f.write(response.content)
        print("Saved as " + file_name)
    else:
        print("Error: " + response.status_code)
        return None


def main():
    apikey = ""
    # map_modID = "263420"
    modID_to_download = []
    sodium_modID = "394468"
    fabric_modID = "306612"
    modID_to_download.append(sodium_modID)
    modID_to_download.append(fabric_modID)

    game_version = input("Enter game version: ")
    for modID in modID_to_download:
        download_url, file_name = get_download_url(apikey, modID, game_version)
        if download_url is not None:
            saveFile(file_name, download_url)


if __name__ == '__main__':
    main()
