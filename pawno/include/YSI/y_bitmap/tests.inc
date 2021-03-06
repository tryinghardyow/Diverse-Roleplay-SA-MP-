Test:y_bitmap_Fade1()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | (x * y / 256));
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Fade1.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Fade2()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Fade2.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Rect1()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0xFF);
	Bitmap_Write(ctx, "y_bitmap_Rect1.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Rect2()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	Bitmap_DrawRectangle(ctx, 64, 64, 128, 192, Y_YELLOW | 0x80);
	Bitmap_DrawRectangle(ctx, 128, 64, 192, 192, Y_ALICEBLUE | 0x80);
	Bitmap_Write(ctx, "y_bitmap_Rect2.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Rect3()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	Bitmap_DrawRectangle(ctx, 64, 64, 148, 192, Y_YELLOW | 0x80);
	Bitmap_DrawRectangle(ctx, 108, 64, 192, 192, Y_ALICEBLUE | 0x80);
	Bitmap_Write(ctx, "y_bitmap_Rect3.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_FadeRect1()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0x40);
	Bitmap_Write(ctx, "y_bitmap_FadeRect1.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Diagonal1()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	_BMP_PAT@DIAGONAL(0, 0, 0, 0, PATTERN(DIAGONAL, STRIPE1 = 4, STRIPE2 = 4));
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			//Bitmap_WritePixel(ctx, x, y, Y_GREEN | (YSI_gBitmapAlpha[y % YSI_gBitmapAlphaY]{x % YSI_gBitmapAlphaX}));
			new
				alpha = YSI_gBitmapAlpha[y % YSI_gBitmapAlphaY]{x % YSI_gBitmapAlphaX};
			if (alpha == 255)
				Bitmap_WritePixel(ctx, x, y, X11_RED);
			else if (alpha == 0)
				Bitmap_WritePixel(ctx, x, y, X11_WHITE);
			else if (alpha > 127)
				Bitmap_WritePixel(ctx, x, y, X11_GREEN);
			else
				Bitmap_WritePixel(ctx, x, y, X11_BLUE);
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Diagonal1.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Diagonal2()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	_BMP_PAT@DIAGONAL(0, 0, 0, 0, PATTERN(DIAGONAL, STRIPE1 = 2, STRIPE2 = 2));
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | (YSI_gBitmapAlpha[y % YSI_gBitmapAlphaY]{x % YSI_gBitmapAlphaX}));
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Diagonal2.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Diagonal3()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	_BMP_PAT@DIAGONAL(0, 0, 0, 0, PATTERN(DIAGONAL, STRIPE1 = 3, STRIPE2 = 3));
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | (YSI_gBitmapAlpha[y % YSI_gBitmapAlphaY]{x % YSI_gBitmapAlphaX}));
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Diagonal3.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Diagonal4()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	_BMP_PAT@DIAGONAL(0, 0, 0, 0, PATTERN(DIAGONAL, STRIPE1 = 2, STRIPE2 = 4));
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | (YSI_gBitmapAlpha[y % YSI_gBitmapAlphaY]{x % YSI_gBitmapAlphaX}));
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Diagonal4.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Diagonal5()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	_BMP_PAT@DIAGONAL(0, 0, 0, 0, PATTERN(DIAGONAL, STRIPE1 = 4, STRIPE2 = 2));
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | (YSI_gBitmapAlpha[y % YSI_gBitmapAlphaY]{x % YSI_gBitmapAlphaX}));
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Diagonal5.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Diagonal6()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	_BMP_PAT@DIAGONAL(0, 0, 0, 0, PATTERN(DIAGONAL));
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | (YSI_gBitmapAlpha[y % YSI_gBitmapAlphaY]{x % YSI_gBitmapAlphaX}));
		}
	}
	Bitmap_Write(ctx, "y_bitmap_Diagonal6.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Pattern1()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0x40, .fillPattern = PATTERN(SOLID));
	Bitmap_Write(ctx, "y_bitmap_Pattern1.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Pattern2()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0x40, .fillPattern = PATTERN(DIAGONAL));
	Bitmap_Write(ctx, "y_bitmap_Pattern2.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Pattern3()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0x40, .fillPattern = PATTERN(DIAGONAL, STRIPE1 = 16));
	Bitmap_Write(ctx, "y_bitmap_Pattern3.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Pattern4()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0x40, .fillPattern = PATTERN(DIAGONAL, STRIPE2 = 16));
	Bitmap_Write(ctx, "y_bitmap_Pattern4.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Pattern5()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0x40, .fillPattern = PATTERN(DIAGONAL, STRIPE1 = 16, STRIPE2 = 8));
	Bitmap_Write(ctx, "y_bitmap_Pattern5.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Pattern6()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0x40, .fillPattern = PATTERN(DIAGONAL, STRIPE1 = 16, STRIPE2 = 8, RIGHT));
	Bitmap_Write(ctx, "y_bitmap_Pattern6.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Pattern7()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0x40, .fillPattern = PATTERN(STRIPED));
	Bitmap_Write(ctx, "y_bitmap_Pattern7.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Pattern8()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	for (new y = 0; y != 256; ++y)
	{
		for (new x = 0; x != 256; ++x)
		{
			Bitmap_WritePixel(ctx, x, y, Y_RED | y);
			Bitmap_WritePixel(ctx, x, y, Y_GREEN | x);
		}
	}
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_YELLOW | 0x40, .fillPattern = PATTERN(STRIPED, HORIZONTAL));
	Bitmap_Write(ctx, "y_bitmap_Pattern8.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Border1()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, 0, X11_ROYALBLUE);
	Bitmap_Write(ctx, "y_bitmap_Border1.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Border2()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, 0, X11_ROYALBLUE, .linePattern = PATTERN(SOLID, BORDER = 16));
	Bitmap_Write(ctx, "y_bitmap_Border2.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Border3()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, 0, X11_ROYALBLUE, .linePattern = PATTERN(DIAGONAL, BORDER = 32));
	Bitmap_Write(ctx, "y_bitmap_Border3.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Border4()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, 0, X11_ROYALBLUE, .linePattern = PATTERN(DOTTED));
	Bitmap_Write(ctx, "y_bitmap_Border4.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Border5()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, 0, X11_ROYALBLUE, .linePattern = PATTERN(DOTTED, STRIPE1 = 16, STRIPE2 = 4));
	Bitmap_Write(ctx, "y_bitmap_Border5.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Border6()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(256, 256);
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, 0, X11_ROYALBLUE, .linePattern = PATTERN(DOTTED, STRIPE1 = 1, STRIPE2 = 8));
	Bitmap_Write(ctx, "y_bitmap_Border6.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Large1()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(512, 512);
	Bitmap_DrawRectangle(ctx, 64, 64, 192, 192, Y_LAVENDER | 0xFF);
	Bitmap_Write(ctx, "y_bitmap_Large1.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Large2()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(512, 512);
	Bitmap_DrawRectangle(ctx, 0, 0, 256, 256, Y_LAVENDER | 0xFF);
	Bitmap_Write(ctx, "y_bitmap_Large2.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Large3()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(512, 512);
	Bitmap_DrawRectangle(ctx, 64, 64, 512, 512, Y_LAVENDER | 0xFF);
	Bitmap_Write(ctx, "y_bitmap_Large3.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Large4()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(512, 512);
	Bitmap_DrawRectangle(ctx, 64, 64, 70, 500, Y_LAVENDER | 0xFF);
	Bitmap_Write(ctx, "y_bitmap_Large4.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_Large5()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(512, 512);
	Bitmap_DrawRectangle(ctx, 64, 64, 500, 70, Y_LAVENDER | 0xFF);
	Bitmap_Write(ctx, "y_bitmap_Large5.bmp");
	Bitmap_Destroy(ctx);
}

Test:y_bitmap_VLarge1()
{
	new
		Bitmap:ctx;
	ctx = Bitmap_Create(1024, 1024);
	Bitmap_DrawRectangle(ctx, 256, 256, 768, 768, Y_MINTCREAM | 0xFF);
	Bitmap_Write(ctx, "y_bitmap_VLarge1.bmp");
	Bitmap_Destroy(ctx);
}
