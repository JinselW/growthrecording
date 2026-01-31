def make_album(singer_name, album_name, sing_num = None):
    music = {'singer' : singer_name, 'album' : album_name}
    if sing_num:
        music['sing_num'] = sing_num
    return music

albums = []
num = int(input('请输入要输入专辑的总数量：'))
while num:
    num -= 1
    singer = input('请输入歌手名：')
    album = input('请输入专辑名：')
    singnum = None
    judge = input('是否输入歌曲数量：')
    if judge == '是':
        singnum = input('请输入歌曲数量：')
    album = make_album(singer, album, singnum)
    albums.append(album)

for album in albums:
    print(f'\n{album}')
