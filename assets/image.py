from PIL import Image, ImageEnhance

im_d = Image.open("bg_d_raw.png")
im_t = Image.open("bg_t_raw.png")

im_d = ImageEnhance.Color(im_d)
im_d = im_d.enhance(0.8)
im_d = ImageEnhance.Brightness(im_d)
im_d = im_d.enhance(1)

im_t = ImageEnhance.Color(im_t)
im_t = im_t.enhance(1)
im_t = ImageEnhance.Brightness(im_t)
im_t = im_t.enhance(0.9)

im_bg_d = im_d.resize((1200,1000))
im_bg_d_fp = im_bg_d.transpose(Image.FLIP_LEFT_RIGHT)

im_bg_t = im_t.resize((1200,1000))
im_bg_t_fp = im_bg_t.transpose(Image.FLIP_LEFT_RIGHT)

im_new = Image.new('RGB', (12000, 2000))
for i in range(5):
    im_new.paste(im_bg_t, (i*2*1200,0))
    im_new.paste(im_bg_t_fp, ((i*2+1)*1200,0))
    
    im_new.paste(im_bg_d_fp, (i*2*1200,1000))
    im_new.paste(im_bg_d, ((i*2+1)*1200,1000))
    
im_new.save("res.png", "PNG")

