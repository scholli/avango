// -*- Mode:C++ -*-

/************************************************************************\
*                                                                        *
* This file is part of Avango.                                           *
*                                                                        *
* Copyright 1997 - 2008 Fraunhofer-Gesellschaft zur Foerderung der       *
* angewandten Forschung (FhG), Munich, Germany.                          *
*                                                                        *
* Avango is free software: you can redistribute it and/or modify         *
* it under the terms of the GNU Lesser General Public License as         *
* published by the Free Software Foundation, version 3.                  *
*                                                                        *
* Avango is distributed in the hope that it will be useful,              *
* but WITHOUT ANY WARRANTY; without even the implied warranty of         *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
* GNU General Public License for more details.                           *
*                                                                        *
* You should have received a copy of the GNU Lesser General Public       *
* License along with Avango. If not, see <http://www.gnu.org/licenses/>. *
*                                                                        *
* Avango is a trademark owned by FhG.                                    *
*                                                                        *
\************************************************************************/

#if !defined(AVANGO_TOOLS_OBJECTSELECTOR_H)
#define AVANGO_TOOLS_OBJECTSELECTOR_H

/**
 * \file
 * \ingroup av_tools
 */

#include <avango/tools/Selector.h>
#include "windows_specific_tools.h"


namespace av
{
  namespace tools
  {
    /**
     * ObjectSelector class selects targets from given av::Objects.
     *
     * \ingroup av_tools
     */
    class AV_TOOLS_DLL ObjectSelector : public Selector
    {
      AV_FC_DECLARE();

    public:

      /**
       * Constructor.
       */
      ObjectSelector();

    protected:

      /**
       * Destructor made protected to prevent allocation on stack.
       */
      virtual ~ObjectSelector();

    public:

      /**
       * Defines the input targets from which the objects are selected.
       */
      MFTargetHolder Targets;

      /**
       * Defines the objects which may be selected. The output is in SelectedTargets.
       */
      MFObject SelectableObjects;

      /**
       * Defines additional selectable objects wihch may come as output from another Selector.
       */
      MFTargetHolder SelectableTargets;

      /**
       * Set to true if the selectable objects should also be searched in the OSG node paths
       * found in NodePathTargetHolder objects.
       */
      SFBool SearchTargetHolderNodePaths;

      /**
       * Set to true if the selectable objects should also be searched in the OSG node paths.
       */
      SFBool SearchOSGNodePaths;

      /* virtual */ void evaluate();

    };

    typedef SingleField<Link<ObjectSelector> > SFObjectSelector;
    typedef MultiField<Link<ObjectSelector> > MFObjectSelector;
  }

#ifdef AV_INSTANTIATE_FIELD_TEMPLATES
  template class AV_TOOLS_DLL SingleField<Link<tools::ObjectSelector> >;
  template class AV_TOOLS_DLL MultiField<Link<tools::ObjectSelector> >;
#endif

}

#endif
