/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2023-12-20 09:16:37
 * @LastEditors: Clark
 * @LastEditTime: 2023-12-20 10:55:39
 * @Description: file content
 */

#include <utility>
// for move, we don't supply a using declaration for move

#include <iostream>
using std::cerr;
using std::endl;

#include <set>
using std::set;

#include <string>
using std::string;

#include "Folder.h"

void swap(Message &lhs, Message &rhs)
{
    using std::swap;

    for (auto &f : lhs.folders)
    {
        f->remMsg(&lhs);
    }

    for (auto &f : rhs.folders)
    {
        f->remMsg(&rhs);
    }

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto &f : lhs.folders)
    {
        f->addMsg(&lhs);
    }

    for (auto &f : rhs.folders)
    {
        f->addMsg(&rhs);
    }
}

Folder::Folder(Folder &&f)
{
	move_Message(&f);   // make each Message point to this Folder
}

Folder& Folder::operator=(Folder &&f)
{
    if (this != &f)
    {
        remove_from_Msgs();
        move_Message(&f);
    }

    return *this;
}

void Folder::move_Message(Folder *f)
{
    msgs = std::move(f->msgs);
    f->msgs.clear();

    for (auto m : msgs)
    {
        m->remFldr(f);
        m->addFldr(this);
    }
}

Message::Message(Message &&m): contents(std::move(m.contents))
{
    move_Folders(&m);
}

Message::Message(const Message &m): contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message& Message::operator=(Message &&rhs)
{
    if (this != &rhs)
    {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);
    for (auto f : folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
    {
        f->remMsg(this);
    }
    folders.clear();
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto msg : f.msgs)
    {
        msg->addFldr(this);
    }
}

Folder::Folder(const Folder &f): msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder& Folder::operator=(const Folder &f)
{
    remove_from_Msgs();
    msgs = f.msgs;
    add_to_Messages(f);
    return *this;
}

Folder::~Folder()
{
    remove_from_Msgs();
}

void Folder::remove_from_Msgs()
{
    while (!msgs.empty())
    {
        (*msgs.begin())->remove(*this);
    }
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Folder::save(Message &m)
{
    msgs.insert(&m);
    m.addFldr(this);
}

void Folder::remove(Message &m)
{
    msgs.erase(&m);
    m.remFldr(this);
}

void Folder::debug_print()
{
    cerr << "Folder contains " << msgs.size() << " message " << endl;
    int ctr = 1;

    for (auto m : msgs)
    {
        cerr << "Message" << ctr++ << ":\n\t" << m->contents << endl;
    }
}

void Message::debug_print()
{
    cerr << "Message:\n\t" << contents << endl;
    cerr << "Appears in" << folders.size() << " Folders" << endl;
}
