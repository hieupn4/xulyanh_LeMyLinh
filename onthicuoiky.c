void OnChucnangTachbiengra()
{
	// TODO: Add your command handler code here
	Conthicuoiky2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	BYTE Y[1000][1000];
	if (!pDoc)
		return;
	else
		{
			// sử dụng toán tử Sobel
			int Hm[3][3] ={{-1,0,1},{-1,0,1},{-1,0,1}};
			int Hn[3][3] = {{-1,-1,-1},{0,0,0},{1,1,1}};
			// ngưỡng anpha
			int anpha = 100;
			for(int i=0;i<pDoc->bi.biHeight;i++)
				for(int j=0;j<pDoc->bi.biWidth;j++)
					{
						int Gm =0;
						int Gn=0;
						for(int l=0;l<3;l++)
							for(int k=0;k<3;k++)
								{
                                     Gm+=Hm[l][k]*pDoc->X[i-l+1][j-k+1];
					                 Gn+=Hn[l][k]*pDoc->X[i-l+1][j-k+1];
								}
                        if((abs(Gm)+abs(Gn))>=anpha)
							Y[i][j] = 255;
						else
							Y[i][j] = 0;
					}
				for(int i=0;i<pDoc->bi.biHeight;i++)
					for(int j=0;j<pDoc->bi.biWidth;j++)
			           pDoc->X[i][j]=Y[i][j];
		Invalidate();

		}

}


void OnChucnangTachbienlaplace()
{
	// TODO: Add your command handler code here
	Conthicuoiky2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	BYTE Y[1000][1000];
	if (!pDoc)
		return;
	else
		{
			// sử dụng toán tử
			int H[3][3] ={{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};
			// ngưỡng anpha
			int anpha = 30;
			for(int i=0;i<pDoc->bi.biHeight;i++)
				for(int j=0;j<pDoc->bi.biWidth;j++)
					{
						int G =0;
						for(int l=0;l<3;l++)
							for(int k=0;k<3;k++)
                                     G+=H[l][k]*pDoc->X[i-l+1][j-k+1];
                        if(G<=anpha)
							Y[i][j] = 255;
						else
							Y[i][j] = 0;
					}
				for(int i=0;i<pDoc->bi.biHeight;i++)
					for(int j=0;j<pDoc->bi.biWidth;j++)
			           pDoc->X[i][j]=Y[i][j];
		Invalidate();

		}
}


void OnChucnangTachbienlaban()
{
	// TODO: Add your command handler code here
	Conthicuoiky2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	BYTE Y[1000][1000];
	if (!pDoc)
		return;
	else
		{
			// sử dụng toán tử Sobel
			int H1[3][3] ={{5,5,5},{-3,0,-3},{-3,-3,-3}};
			int H2[3][3] = {{-3,5,5},{-3,0,5},{-3,-3,-3}};

			int H3[3][3] = {{-3,-3,5},{-3,0,5},{-3,-3,5}};
			int H4[3][3] = {{-3,-3,-3},{-3,0,5},{-3,5,5}};

			int H5[3][3] = {{-3,-3,-3},{-3,0,-3},{5,5,5}};

			int H6[3][3] = {{-3,-3,-3},{5,0,-3},{5,5,-3}};

			int H7[3][3] = {{5,-3,-3},{5,0,-3},{5,-3-3}};

			int H8[3][3] = {{5,5,-3},{5,0,-3},{-3,-3,-3}};

			// ngưỡng anpha
			int anpha = 100;
			for(int i=0;i<pDoc->bi.biHeight;i++)
				for(int j=0;j<pDoc->bi.biWidth;j++)
					{
						int G1 =0;
						int G2=0;
						int G3=0;
						int G4=0;
						int G5=0;
						int G6=0;
						int G7=0;
						int G8=0;
						for(int l=0;l<3;l++)
							for(int k=0;k<3;k++)
								{
                                     G1+=H1[l][k]*pDoc->X[i-l+1][j-k+1];
					                 G2+=H2[l][k]*pDoc->X[i-l+1][j-k+1];
									 G3+=H3[l][k]*pDoc->X[i-l+1][j-k+1];
									 G4+=H4[l][k]*pDoc->X[i-l+1][j-k+1];
									 G5+=H5[l][k]*pDoc->X[i-l+1][j-k+1];
									 G6+=H6[l][k]*pDoc->X[i-l+1][j-k+1];
									 G7+=H7[l][k]*pDoc->X[i-l+1][j-k+1];
									 G8+=H8[l][k]*pDoc->X[i-l+1][j-k+1];
								}
						int A[8];
						A[0] = G1;
						A[1] = G2;
						A[2] = G3;
						A[3] = G4;
						A[4] = G5;
						A[5] = G6;
						A[6] = G7;
						A[7] = G8;

                        int max=abs(A[0]);
		for(int m=1;m<8;m++)
		if(max<abs(A[m])) max=A[m];
		if(abs(max)>=anpha)
		Y[i][j]=255;
		else
		Y[i][j]=0;

					}
				for(int i=0;i<pDoc->bi.biHeight;i++)
					for(int j=0;j<pDoc->bi.biWidth;j++)
			           pDoc->X[i][j]=Y[i][j];
		Invalidate();

		}
}


void phananh3vung()
{
	// TODO: Add your command handler code here
	Conthicuoiky2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int i,j,M,N,n1,n2,n3,T1=50,T2=200;
	int tong1,tong2,tong3;
	tong1=tong2=tong3=n1=n2=n3=0;
	M=pDoc->bi.biHeight;
	N=pDoc->bi.biWidth;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
	{
		if(pDoc->X[i][j]<T1)
		{
			n1++;
			tong1+=pDoc->X[i][j];
		}
		else
		if(pDoc->X[i][j]<T2)
		{
			n2++;
			tong2+=pDoc->X[i][j];
		}
		else
		{
			n3++;
			tong3+=pDoc->X[i][j];
		}
	}
	tong1/=n1;tong2/=n2;tong3/=n3;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
	 {
		if(pDoc->X[i][j]<T1)
		pDoc->X[i][j]=tong1;
		else
		if(pDoc->X[i][j]<T2)
		pDoc->X[i][j]=tong2;
		else
		pDoc->X[i][j]=tong3;
	}
	Invalidate();

}
