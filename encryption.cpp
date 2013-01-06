/*
End Semester Project Computer Fundamentals 
BEE-1B
Ms. Samin Khaliq
---------------------------------------------------------------------------
Implementation of a Xor Multivariable shifting and transposition Algorithm.
---------------------------------------------------------------------------
Umair Aftab (104)
Hassam Ali Khan (35)
---------------------------------------------------------------------------

© Intellectual Property of 
Umair Aftab && Hassam Ali Khan 
*/


#include<iostream>
#include<fstream>
using namespace std; 

//char original_matrix[10][10]; // so that retains original 
char encr_matrix[10][10];
char xor_matrix[10][10];
int size =10;
char original_matrix[10][10];

struct key_var
{
	char ori_key ; // original key 
	char keyvar ; // key variants intialized
} 
key[10];



void martix_copy()
{
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size ; y++)
		{
			encr_matrix[x][y]= original_matrix[x][y] ;
		}
	}
	cout<<endl<< "Matrix Copy complete"<<endl ; // check point q2
}
	

void key_gen(void) // generates encrypting key 
{
	for (int x=0 ; x<size ; x++)
	{
		
		int gen=rand()%256;
		static_cast<char> (gen);
		if (x==0)
		{key[x].ori_key=gen ;}
		else 
		{
			key[x].ori_key=gen;
		}
	}
	cout<<endl<<"Key defined"<<endl ;
	//  check point q1
	for (int x=0; x<size ;x++)
	{
		cout << key[x].ori_key<<endl;
	}
	cout <<endl<< "End of Key generation" <<endl ;
	
} // end of key generation  key generated 
void key_derivants() 
{
	for (int x=0; x<size ; x++)
	{
		if (x<(size-3)) 
		{
			key[x].keyvar=key[x].ori_key +key[x+1].ori_key; // for key variants 
		}
		else if (x>=(size-3))
		{
			key[x].keyvar=key[x].ori_key+key[x-1].ori_key; // for last key variant 
		}
	}
	cout << "Key derivants defined"<<endl;
		for (int x=0; x<size ;x++)
	{
		cout << key[x].keyvar<<endl ; 
	}
}

void transpose_matrix()
{
	cout << "encrypted matrix print before  transpose" << endl ; 
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << encr_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	} cout  <<endl;

	int temp_matrix[10][10] ;

	for (int x=0 ; x<size ; x++)
	{
		for (int y=0; y<size ; y++)
		{
			temp_matrix[y][x]=encr_matrix[x][y] ;
		}
	} // transpose made. 
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0; y<size ; y++)
		{
			encr_matrix[x][y]=temp_matrix[x][y];
		}
	} // transpose transfered to original encr matrix. 
	
	cout<< "Transposition complete"<<endl ; 
	cout << "encrypted matrix print after transpose" << endl ; 
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << encr_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	}cout << endl;
}

void shift()
{
	cout << "encrypted matrix print before  shift" << endl ; 
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << encr_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	} cout <<endl;
	int rem;
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size ; y++)
		{
			rem=y%2;
			if (rem==0)
			{
				encr_matrix[x][y]=encr_matrix[x][y]+key[y].ori_key ;
			}
			else
			{
				encr_matrix[x][y]=encr_matrix[x][y]+key[y].keyvar;
			}

		}
		
	}
	cout << "Shift complete"<<endl ;
	cout << "encrypted matrix print at shift" << endl ; 
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << encr_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	} cout <<endl;
} // shift complete 
void xor_shift()
{
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size ; y++)
		{
			encr_matrix[x][y]=encr_matrix[x][y]^key[y].ori_key;

		}
	}
	cout << "Xor shift of matrix" <<endl; 
}

void matrix_print()
{
	cout << "Original matrix print" << endl ;
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << original_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	}
	cout << "encrypted matrix print" << endl ; 
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << encr_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	}
}

/*
-----------------------------------------------------------------------------------------------
|							ENCRYPTION PART OF SOL ENDs    									  |
-----------------------------------------------------------------------------------------------
*/

/*
************************************************************************************************ 
								DECRYPTION STARTS
************************************************************************************************
*/

char decode_matrix[10][10];
char encrypt_matrix[10][10];
struct decode_key
{
	char org_key;
	char key_dev;
}
dec_key[10];

void load_encrmatix()
{
	for (int x=0 ; x<size; x++)
	{
		for (int y=0 ; y<size ; y++)
		{
			decode_matrix[x][y]=encrypt_matrix[x][y];
		}
	}
	cout << "Matrix loaded.."<<endl;
}

void keyderv_gen()
{
	for (int x=0; x<size ; x++)
	{
		if (x<(size-3)) 
		{
			dec_key[x].key_dev=dec_key[x].org_key +dec_key[x+1].org_key; // for key variants 
		}
		else if (x>=(size-3))
		{
			dec_key[x].key_dev=dec_key[x].org_key +dec_key[x-1].org_key; // for last key variant 
		}
	}
	cout << "dec Key derivants defined"<<endl;
		for (int x=0; x<size ;x++)
	{
		cout << key[x].keyvar<<endl ; 
	}
}
void dec_transpose_matrix()
{
	int temp_matrix[10][10] ;

	for (int x=0 ; x<size ; x++)
	{
		for (int y=0; y<size ; y++)
		{
			temp_matrix[y][x]=decode_matrix[x][y] ;
		}
	} // transpose made. 
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0; y<size ; y++)
		{
			decode_matrix[x][y]=temp_matrix[x][y];
		}
	} // transpose transfered to original encr matrix. 
	
	cout<< "Reverse Transposition complete"<<endl ; 
}

void dec_shift()
{
	int rem;
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size ; y++)
		{
			rem=y%2;
			if (rem==0)
			{
				decode_matrix[x][y]=decode_matrix[x][y]-dec_key[y].org_key ;
			}
			else
			{
				decode_matrix[x][y]=decode_matrix[x][y]-dec_key[y].key_dev;
			}

		}
		
	}
	cout << " Reverse Multivariable Shift complete"<<endl ;
	} // reverse shift complete

void dec_xor_shift()
{
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size ; y++)
		{
			decode_matrix[x][y]=decode_matrix[x][y]^key[y].ori_key;

		}
	}
	cout << "Reverse Xor shift of matrix" <<endl; 
}

void dec_print_matrix()
{
	cout << "encrypted matrix print" << endl ;
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << encrypt_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	}
	cout <<endl<< "decrypted matrix print" << endl ; 
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << decode_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	}
}


/*
*********************************************************************************
							I/O
*********************************************************************************
*/
void read_plain_text()
{
	ifstream outfile("plaintext.txt");
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0; y<size; y++)
		{
			outfile>>original_matrix[x][y];
		}
	}
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << original_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	}
	cout << "*********************************************"<<endl<<"plain text loaded"<<endl;


}
void output_encrypted_text()
{
	ofstream file("encrtext.doc");
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0; y<size; y++)
		{
			file<<encr_matrix[x][y];
			file<<" ";
		}
		file<<endl;
	}
	cout<<endl<< "Encrypted File Written"<<endl;
	ofstream bfile("key.txt");
	for (int x=0 ; x<size ; x++)
	{
		bfile<<key[x].ori_key;
		bfile<<" ";
	}
	cout<<endl<<"Key Output"<<endl;

}
void read_encrypted_text()
{
	ifstream afile("key.txt");
	for (int x=0 ; x<size ; x++)
	{
		afile>>dec_key[x].org_key;
	}
	cout<<endl<<"Loading Decrypting key"<<endl;
	for (int x=0 ; x<size ; x++)
	{
		cout<<endl<<dec_key[x].org_key<<endl;
	}
	cout<< endl<<"Key Loaded"<<endl;

	ifstream outfile("encrtext.doc");
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0; y<size; y++)
		{
			outfile>>encrypt_matrix[x][y];
		}
	}
	for (int x=0 ; x<size ; x++)
	{
		for (int y=0 ; y<size; y++)
		{
			cout << encrypt_matrix[x][y]<<" " ;
		}
		cout << endl ; 
	}
	cout << "*********************************************"<<endl<<"encrypted text loaded"<<endl;
}


/*
**********************************************************************************
						MAIN FUNCTION
**********************************************************************************
*/
void main ()
{
	read_plain_text();
	
	// encryption begins
	martix_copy(); // loads matrix 
	key_gen();     // keys generated 
	key_derivants(); //key derivants generated
	transpose_matrix(); //transpose of matrix 
	shift();  //character shifting 
	xor_shift(); //done
	matrix_print();
	// encryption finish
	
	output_encrypted_text();
	
	cout <<endl<<"****************************************************"<<endl;
	cout <<" Decryption Begins" <<endl;
	
	read_encrypted_text();
	load_encrmatix();
	keyderv_gen();
	dec_xor_shift();
	dec_shift();
	dec_transpose_matrix();
	dec_print_matrix();

	cout <<endl<< "End of Decryption"<<endl;

	system("PAUSE");
}

	
