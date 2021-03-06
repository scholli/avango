#!/usr/bin/python
# -*- Mode:Python -*-

##########################################################################
#                                                                        #
# This file is part of AVANGO.                                           #
#                                                                        #
# Copyright 1997 - 2009 Fraunhofer-Gesellschaft zur Foerderung der       #
# angewandten Forschung (FhG), Munich, Germany.                          #
#                                                                        #
# AVANGO is free software: you can redistribute it and/or modify         #
# it under the terms of the GNU Lesser General Public License as         #
# published by the Free Software Foundation, version 3.                  #
#                                                                        #
# AVANGO is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of         #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           #
# GNU General Public License for more details.                           #
#                                                                        #
# You should have received a copy of the GNU Lesser General Public       #
# License along with AVANGO. If not, see <http://www.gnu.org/licenses/>. #
#                                                                        #
##########################################################################

'''
Learn how to configure a HIDInput device to collect input data based on
the Linux input system.
'''

import sys
import avango.daemon

# enable logging for detailed information on device setup
#avango.enable_logging()

# create a station to propagate the input events
station = avango.daemon.Station('spacemousestation')

# configure a mouse device
spacemouse = avango.daemon.HIDInput()
spacemouse.station = station
if sys.platform == 'win32':
  spacemouse.device = '01::08::1'
else:
  spacemouse.device = '/dev/input/event3'

# map incoming Spacemouse events to station values
spacemouse.values[0] = "EV_ABS::ABS_X"   # trans X
spacemouse.values[1] = "EV_ABS::ABS_Y"   # trans Y
spacemouse.values[2] = "EV_ABS::ABS_Z"   # trans Z
spacemouse.values[3] = "EV_ABS::ABS_RX"  # rotate X
spacemouse.values[4] = "EV_ABS::ABS_RY"  # rotate Y
spacemouse.values[5] = "EV_ABS::ABS_RZ"  # rotate Z

# map incoming button events to station buttons
spacemouse.buttons[0] = "EV_KEY::BTN_BASE3"    # *
spacemouse.buttons[1] = "EV_KEY::BTN_TRIGGER"  # 1
spacemouse.buttons[2] = "EV_KEY::BTN_THUMB"    # 2
spacemouse.buttons[3] = "EV_KEY::BTN_THUMB2"   # 3
spacemouse.buttons[4] = "EV_KEY::BTN_TOP"      # 4
spacemouse.buttons[5] = "EV_KEY::BTN_TOP2"     # 5
spacemouse.buttons[6] = "EV_KEY::BTN_PINKIE"   # 6
spacemouse.buttons[7] = "EV_KEY::BTN_BASE"     # 7
spacemouse.buttons[8] = "EV_KEY::BTN_BASE2"    # 8

# start daemon (will enter the main loop)
avango.daemon.run([spacemouse])
