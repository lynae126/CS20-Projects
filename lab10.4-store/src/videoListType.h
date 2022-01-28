/*
 * videoListType.h
 *
 *  Created on: Mar 23, 2021
 *      Author: cc
-----------------------------------
 videoListType : public videoType
-----------------------------------
- searchVideoList(string title, bool& found,
  nodeType<videoType>* &current) const : void
-----------------------------------
+ videoSearch(string title) const : bool
+ isVideoAvailable(string title) const : bool
+ videoCheckOut(string title) : void
+ videoCheckIn(string title) : void
+ videoCheckTitle(string title) const : bool
+ videoUpdateInStock(string title, int num) : void
+ videoSetCopiesInStock(string title, int num) : void
+ videoPrintTitle() const : void
-----------------------------------
*/
#ifndef VIDEOLISTTYPE_H_
#define VIDEOLISTTYPE_H_
#include <iostream>
#include <string>
#include "LinkedListType.h"
#include "videoType.h"
using namespace std;

class videoListType:public linkedListType<videoType>{
	private:
	   void searchVideoList(string title, bool& found,
							nodeType<videoType>* &current) const;
	public:
		bool videoSearch(string title) const;
		bool isVideoAvailable(string title) const;
		void videoCheckOut(string title);
		void videoCheckIn(string title);
		bool videoCheckTitle(string title) const;
		void videoUpdateInStock(string title, int num);
		void videoSetCopiesInStock(string title, int num);
		void videoPrintTitle() const;
};

//This function searches the video list for a particular
//video, specified by the parameter title.
//Postcondition: If the video is found, the parameter found is
//    set to true, otherwise it is set to false. The parameter
//    current points to the node containing the video.
void videoListType::searchVideoList(string title, bool& found,
                         nodeType<videoType>* &current) const{
    found = false;   //set found to false
    current = first; //set current to point to the first node in the list
    while (current != NULL && !found)     //search the list
        if (current->info.checkTitle(title)) //the item is found
            found = true;
        else
            current = current->link; //advance current to
                                     //the next node
}//end searchVideoList

//Function to determine whether a copy of a particular
//video is in the store.
//Postcondition: Returns true if at least one copy of the
//    video specified by title is in the store, and false
//    otherwise.
bool videoListType::isVideoAvailable(string title) const{
    bool found;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if (found)
        found = (location->info.getNoOfCopiesInStock() > 0);
    else
        found = false;
    return found;
}

//Function to check in a video returned by a customer.
//Postcondition: copiesInStock is incremented by one.
void videoListType::videoCheckIn(string title){
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location); //search the list
    if (found)
        location->info.checkIn();
    else
        cout << "The store does not carry " << title << endl;
}

//Function to check out a video, that is, rent a video.
//Postcondition: copiesInStock is decremented by one.
void videoListType::videoCheckOut(string title){
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location); //search the list
    if (found)
        location->info.checkOut();
    else
        cout << "The store does not carry " << title << endl;
}

//Function to determine whether a particular video is in
//the store.
//Postcondition: Returns true if the video’s title is the
//    same as title, and false otherwise.
bool videoListType::videoCheckTitle(string title) const{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location); //search the list
    return found;
}

//Function to update the number of copies of a video
//by adding the value of the parameter num. The
//parameter title specifies the name of the video for
//which the number of copies is to be updated.
//Postcondition: copiesInStock = copiesInStock + num;
void videoListType::videoUpdateInStock(string title, int num){
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location); //search the list
    if (found)
        location->info.updateInStock(num);
    else
        cout << "The store does not carry " << title << endl;
}

//Function to reset the number of copies of a video.
//The parameter title specifies the name of the video
//for which the number of copies is to be reset, and the
//parameter num specifies the number of copies.
//Postcondition: copiesInStock = num;
void videoListType::videoSetCopiesInStock(string title, int num){
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    if (found)
        location->info.setCopiesInStock(num);
    else
        cout << "The store does not carry " << title << endl;
}

//Function to search the list to see whether a
//particular title, specified by the parameter title,
//is in the store.
//Postcondition: Returns true if the title is found, and
//    false otherwise.
bool videoListType::videoSearch(string title) const{
    bool found = false;
    nodeType<videoType> *location;
    searchVideoList(title, found, location);
    return found;
}

//Function to print the titles of all the videos in the store.
void videoListType::videoPrintTitle() const{
    nodeType<videoType>* current;
    current = first;
    while (current != NULL){
        current->info.printTitle();
        current = current->link;
    }
}
#endif /* VIDEOLISTTYPE_H_ */
