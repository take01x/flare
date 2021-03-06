/*
 * Flare
 * --------------
 * Copyright (C) 2008-2014 GREE, Inc.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
/**
 *	queue_node_state.h
 *
 *	@author	Kiyoshi Ikehara <kiyoshi.ikehara@gree.net>
 *
 *	$Id$
 */
#ifndef	QUEUE_NODE_STATE_H
#define	QUEUE_NODE_STATE_H

#include "cluster.h"
#include "thread_queue.h"

using namespace std;

namespace gree {
namespace flare {

typedef class queue_node_state queue_node_state;
typedef boost::shared_ptr<queue_node_state> shared_queue_node_state;

/**
 *	node state queue class
 */
class queue_node_state : public thread_queue {
public:
	enum							state_operation {
		state_operation_up,
		state_operation_down,
	};
protected:
	string									_node_server_name;
	int											_node_server_port;
	state_operation					_operation;
public:
	queue_node_state(string node_server_name, int node_server_port, state_operation operation);
	virtual ~queue_node_state();

public:
	string get_node_server_name() { return this->_node_server_name; }
	int get_node_server_port() { return this->_node_server_port; }
	state_operation get_operation() { return this->_operation; }
};

}	// namespace flare
}	// namespace gree

#endif	// QUEUE_NODE_STATE_H
// vim: foldmethod=marker tabstop=2 shiftwidth=2 autoindent
