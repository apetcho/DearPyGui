#include "mvPythonInterface.h"

#include "mvApp.h"

namespace Marvel {

	PyObject* getValue(PyObject* self, PyObject* args)
	{
		const char* name;

		PyArg_ParseTuple(args, "s", &name);

		mvAppItem* item = mvApp::GetApp()->getItem(std::string(name));

		if(item == nullptr)
			return Py_None;

		return item->getPyValue();
	}

	PyObject* setMainCallback(PyObject* self, PyObject* args)
	{
		const char* callback;;

		PyArg_ParseTuple(args, "s", &callback);

		mvApp::GetApp()->setMainCallback(std::string(callback));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* setItemCallback(PyObject* self, PyObject* args)
	{
		const char* callback, * item;

		PyArg_ParseTuple(args, "ss", &item, &callback);

		mvApp::GetApp()->setItemCallback(std::string(item), std::string(callback));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* setItemTip(PyObject* self, PyObject* args)
	{
		const char* tip, * item;

		PyArg_ParseTuple(args, "ss", &item, &tip);

		mvApp::GetApp()->setItemTip(std::string(item), std::string(tip));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* setItemWidth(PyObject* self, PyObject* args)
	{
		const char* item;
		int width;

		PyArg_ParseTuple(args, "si", &item, &width);

		mvApp::GetApp()->setItemWidth(std::string(item), width);

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addButton(PyObject* self, PyObject* args)
	{
		const char* parent, * name;

		PyArg_ParseTuple(args, "ss", &parent, &name);

		mvApp::GetApp()->addButton(std::string(parent), std::string(name));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addInputText(PyObject* self, PyObject* args, PyObject* kwargs)
	{
		const char* parent, *name;
		const char* hint = "";
		static const char* keywords[] = { "parent", "name", "hint", NULL };

		if(!PyArg_ParseTupleAndKeywords(args, kwargs, "ss|$s", const_cast<char**>(keywords), &parent, &name, &hint))
			__debugbreak();

		mvApp::GetApp()->addInputText(std::string(parent), std::string(name), std::string(hint));
		
		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addInputInt(PyObject* self, PyObject* args, PyObject* kwargs)
	{
		const char* parent, * name;
		int default_value = 0;
		static const char* keywords[] = { "parent", "name", "default_value", NULL };

		if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ss|$i", const_cast<char**>(keywords), &parent, &name, &default_value))
			__debugbreak();

		mvApp::GetApp()->addInputInt(std::string(parent), std::string(name), default_value);

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addInputFloat(PyObject* self, PyObject* args, PyObject* kwargs)
	{
		const char* parent, * name;
		float default_value = 0.0f;
		static const char* keywords[] = { "parent", "name", "default_value", NULL };

		if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ss|$f", const_cast<char**>(keywords), &parent, &name, &default_value))
			__debugbreak();

		mvApp::GetApp()->addInputFloat(std::string(parent), std::string(name), default_value);

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addTabBar(PyObject* self, PyObject* args)
	{
		const char* parent, * name;

		PyArg_ParseTuple(args, "ss", &parent, &name);

		mvApp::GetApp()->addTabBar(std::string(parent), std::string(name));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addTab(PyObject* self, PyObject* args)
	{
		const char* parent, * name;

		PyArg_ParseTuple(args, "ss", &parent, &name);

		mvApp::GetApp()->addTab(std::string(parent), std::string(name));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* endTab(PyObject* self, PyObject* args)
	{
		const char* parent;

		PyArg_ParseTuple(args, "s", &parent);

		mvApp::GetApp()->endTab(std::string(parent));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* endTabBar(PyObject* self, PyObject* args)
	{
		const char* parent;

		PyArg_ParseTuple(args, "s", &parent);

		mvApp::GetApp()->endTabBar(std::string(parent));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addMenuBar(PyObject* self, PyObject* args)
	{
		const char* name;

		PyArg_ParseTuple(args, "s", &name);

		mvApp::GetApp()->addMenuBar(std::string(name));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addMenu(PyObject* self, PyObject* args)
	{
		const char* parent, * name;

		PyArg_ParseTuple(args, "ss", &parent, &name);

		mvApp::GetApp()->addMenu(std::string(parent), std::string(name));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* endMenu(PyObject* self, PyObject* args)
	{
		const char* parent;

		PyArg_ParseTuple(args, "s", &parent);

		mvApp::GetApp()->endMenu(std::string(parent));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* endMenuBar(PyObject* self, PyObject* args)
	{
		const char* parent;

		PyArg_ParseTuple(args, "s", &parent);

		mvApp::GetApp()->endMenuBar(std::string(parent));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addMenuItem(PyObject* self, PyObject* args)
	{
		const char* parent, * name;

		PyArg_ParseTuple(args, "ss", &parent, &name);

		mvApp::GetApp()->addMenuItem(std::string(parent), std::string(name));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addSpacing(PyObject* self, PyObject* args, PyObject* kwargs)
	{
		const char* parent;
		int count = 1;
		static const char* keywords[] = { "parent", "count", NULL };

		if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s|i", const_cast<char**>(keywords), &parent, &count))
			__debugbreak();

		mvApp::GetApp()->addSpacing(std::string(parent), count);

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addSameLine(PyObject* self, PyObject* args, PyObject* kwargs)
	{
		const char* parent;
		float xoffset = 0.0f;
		float spacing = 0.0f;
		static const char* keywords[] = { "parent", "xoffset", "spacing", NULL };

		if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s|ff", const_cast<char**>(keywords), &parent, &xoffset, &spacing))
			__debugbreak();

		mvApp::GetApp()->addSameLine(std::string(parent), xoffset, spacing);

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addRadioButton(PyObject* self, PyObject* args, PyObject* kwargs)
	{
		const char* parent;
		const char* name;
		PyObject* items;
		int default_value = 0;
		static const char* keywords[] = { "parent", "name", "items", "default_value", NULL };

		if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ssO|i", const_cast<char**>(keywords), &parent, &name, &items, &default_value))
			__debugbreak();

		std::vector<std::string> sitems;

		for (int i = 0; i < PyTuple_Size(items); i++)
			sitems.emplace_back(PyUnicode_AsUTF8(PyTuple_GetItem(items, i)));

		mvApp::GetApp()->addRadioButtons(std::string(parent), std::string(name), sitems, default_value);

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addGroup(PyObject* self, PyObject* args)
	{
		const char* parent, * name;

		PyArg_ParseTuple(args, "ss", &parent, &name);

		mvApp::GetApp()->addGroup(std::string(parent), std::string(name));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* endGroup(PyObject* self, PyObject* args)
	{
		const char* parent;

		PyArg_ParseTuple(args, "s", &parent);

		mvApp::GetApp()->endGroup(std::string(parent));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addChild(PyObject* self, PyObject* args)
	{
		const char* parent, * name;
		int width, height;

		PyArg_ParseTuple(args, "ssii", &parent, &name, &width, &height);

		mvApp::GetApp()->addChild(std::string(parent), std::string(name), width, height);

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* endChild(PyObject* self, PyObject* args)
	{
		const char* parent;

		PyArg_ParseTuple(args, "s", &parent);

		mvApp::GetApp()->endChild(std::string(parent));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addTooltip(PyObject* self, PyObject* args)
	{
		const char* parent, * name;

		PyArg_ParseTuple(args, "ss", &parent, &name);

		mvApp::GetApp()->addTooltip(std::string(parent), std::string(name));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* endTooltip(PyObject* self, PyObject* args)
	{
		const char* parent;

		PyArg_ParseTuple(args, "s", &parent);

		mvApp::GetApp()->endTooltip(std::string(parent));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addCollapsingHeader(PyObject* self, PyObject* args)
	{
		const char* parent, * name;

		PyArg_ParseTuple(args, "ss", &parent, &name);

		mvApp::GetApp()->addCollapsingHeader(std::string(parent), std::string(name));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* setTheme(PyObject* self, PyObject* args)
	{
		const char* theme;

		PyArg_ParseTuple(args, "s", &theme);

		mvApp::GetApp()->setAppTheme(std::string(theme));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addSeperator(PyObject* self, PyObject* args)
	{
		const char* parent;

		PyArg_ParseTuple(args, "s", &parent);

		mvApp::GetApp()->addSeperator(std::string(parent));

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addColorEdit4(PyObject* self, PyObject* args)
	{
		const char* parent, * name;
		float r, g, b, a;

		PyArg_ParseTuple(args, "ssffff", &parent, &name, &r, &g, &b, &a);

		mvApp::GetApp()->addColorEdit4(std::string(parent), std::string(name), r, g, b, a);

		Py_INCREF(Py_None);

		return Py_None;
	}

	PyObject* addCheckbox(PyObject* self, PyObject* args, PyObject* kwargs)
	{
		const char* parent, * name;
		int default_value = 0;
		static const char* keywords[] = { "parent", "name", "default_value", NULL };

		if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ss|$i", const_cast<char**>(keywords), &parent, &name, &default_value))
			__debugbreak();

		mvApp::GetApp()->addCheckbox(std::string(parent), std::string(name), default_value);

		Py_INCREF(Py_None);

		return Py_None;
	}

	void CreatePythonInterface(mvPythonModule& pyModule, PyObject* (*initfunc)())
	{
		pyModule.addMethod(addColorEdit4, "Not Documented");
		pyModule.addMethod(addSeperator, "Not Documented");
		pyModule.addMethod(setTheme, "Not Documented");
		pyModule.addMethod(setMainCallback, "Not Documented");
		pyModule.addMethod(setItemCallback, "Not Documented");
		pyModule.addMethod(setItemTip, "Not Documented");
		pyModule.addMethod(setItemWidth, "Not Documented");
		pyModule.addMethod(addButton, "Not Documented");
		pyModule.addMethod(addInputText, "Not Documented");
		pyModule.addMethod(addInputInt, "Not Documented");
		pyModule.addMethod(addInputFloat, "Not Documented");
		pyModule.addMethod(addRadioButton, "Not Documented");
		pyModule.addMethod(addCheckbox, "Not Documented");
		pyModule.addMethod(addGroup, "Not Documented");
		pyModule.addMethod(endGroup, "Not Documented");
		pyModule.addMethod(addChild, "Not Documented");
		pyModule.addMethod(endChild, "Not Documented");
		pyModule.addMethod(addTabBar, "Not Documented");
		pyModule.addMethod(addTab, "Not Documented");
		pyModule.addMethod(endTab, "Not Documented");
		pyModule.addMethod(endTabBar, "Not Documented");
		pyModule.addMethod(addMenuBar, "Not Documented");
		pyModule.addMethod(addMenu, "Not Documented");
		pyModule.addMethod(endMenu, "Not Documented");
		pyModule.addMethod(endMenuBar, "Not Documented");
		pyModule.addMethod(addMenuItem, "Not Documented");
		pyModule.addMethod(addSpacing, "Not Documented");
		pyModule.addMethod(addSameLine, "Not Documented");
		pyModule.addMethod(addTooltip, "Not Documented");
		pyModule.addMethod(endTooltip, "Not Documented");
		pyModule.addMethod(getValue, "Not Documented");
		pyModule.addMethod(addCollapsingHeader, "Not Documented");

		PyImport_AppendInittab(pyModule.getName() , initfunc);
	}
}