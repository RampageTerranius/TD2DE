#pragma once
//handling dealing with user interface and the likes

class cUI : public cObject
{
	private:
		bool Active;
		string Name;


	public:
		cUI();
		void Delete();
		string GetName();
		void SetName(string lName);
};

vector <cUI> TD2DE_UI;

cUI::cUI()
{
	Delete();
}

void cUI::Delete()
{
	Active = false;
	cObject::Delete();
}

string cUI::GetName()
{
	return Name;
}

void cUI::SetName(string lName)
{
	Name = lName;
}


int TD2DE_CreateUI(int lObjType)
{
	bool lLoop = true;
	while (lLoop)
	{
		int lTotalObjects = TD2DE_UI.size();
		for (int i = 0; i < lTotalObjects; i++)
		{
			if (TD2DE_UI[i].GetObjectID() == -1)
			{
				//set the object id then set its default values as per the object id
				TD2DE_UI[i].SetObjectID(lObjType);

				AddObjectToList(i, TYPE_UI);
				
				return i;
			}
		}
		//if it cant create an object increase the size of the array
		TD2DE_DEBUG.LogError("new value in UI", false);
		TD2DE_DEBUG.LogError("before - c:" + to_string(TD2DE_UI.capacity()) + " s:" + to_string(TD2DE_UI.size()) + " ms:" + to_string(TD2DE_UI.max_size()));
		cUI Temp;
		Temp.Delete();//make sure its a blank object
		TD2DE_UI.push_back(Temp);//push blank object to array
		TD2DE_DEBUG.LogError("after - c:" + to_string(TD2DE_UI.capacity()) + " s:" + to_string(TD2DE_UI.size()) + " ms:" + to_string(TD2DE_UI.max_size()));
	}
	return -1;
}
