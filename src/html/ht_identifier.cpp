#include "ht_identifier.h"
#include "ht_token.h"
#include "../utils/string_switch.h"

namespace newtoo
{

	ht_identifier identify(std::string namestr, bool& is_inline_field, short& flag_field)
	{
		if ((ht_flag)flag_field == ht_flag_not_a_tag)
			return ht_id_text;

		for (size_t i = 0; i < namestr.size(); i++)
			namestr[i] = tolower(namestr[i]);

		while (namestr.length() > 9)
			namestr = namestr.erase(0, 1);

		/* Ќекоторые названи€ пришлось обрезать до 9 символов,
		   среза€ первые буквы, воизбежании коллизии
		*/

		string_switch(namestr)
		{
			string_case("a") : { return ht_id_tag_a; break; }
			string_case("abbr") : { return ht_id_tag_abbr; break; }
			string_case("address") : { return ht_id_tag_address; break; }
			string_case("area") : { return ht_id_tag_area; break; }
			string_case("article") : { return ht_id_tag_article; break; }
			string_case("aside") : { return ht_id_tag_aside; break; }
			string_case("audio") : { return ht_id_tag_audio; break; }
			string_case("b") : { return ht_id_tag_b; break; }
			string_case("base") : { return ht_id_tag_base; break; }
			string_case("bdi") : { return ht_id_tag_bdi; break; }
			string_case("bdo") : { return ht_id_tag_bdo; break; }
			string_case("lockquote") : { return ht_id_tag_blockquote; break; }
			string_case("body") : { return ht_id_tag_body; break; }
			string_case("br") : { return ht_id_tag_br; break; }
			string_case("button") : { return ht_id_tag_button; break; }
			string_case("canvas") : { return ht_id_tag_canvas; break; }
			string_case("caption") : { return ht_id_tag_caption; break; }
			string_case("center") : { return ht_id_tag_center; break; }
			string_case("cite") : { return ht_id_tag_cite; break; }
			string_case("code") : { return ht_id_tag_code; break; }
			string_case("col") : { return ht_id_tag_col; break; }
			string_case("colgroup") : { return ht_id_tag_colgroup; break; }
			string_case("datalist") : { return ht_id_tag_datalist; break; }
			string_case("dd") : { return ht_id_tag_dd; break; }
			string_case("del") : { return ht_id_tag_del; break; }
			string_case("details") : { return ht_id_tag_details; break; }
			string_case("dfn") : { return ht_id_tag_dfn; break; }
			string_case("dialog") : { return ht_id_tag_dialog; break; }
			string_case("div") : { return ht_id_tag_div; break; }
			string_case("dl") : { return ht_id_tag_dl; break; }
			string_case("dt") : { return ht_id_tag_dt; break; }
			string_case("em") : { return ht_id_tag_em; break; }
			string_case("embed") : { return ht_id_tag_embed; break; }
			string_case("fieldset") : { return ht_id_tag_fieldset; break; }
			string_case("igcaption") : { return ht_id_tag_figcaption; break; }
			string_case("figure") : { return ht_id_tag_figure; break; }
			string_case("footer") : { return ht_id_tag_footer; break; }
			string_case("form") : { return ht_id_tag_form; break; }
			string_case("h1") : { return ht_id_tag_h1; break; }
			string_case("h2") : { return ht_id_tag_h2; break; }
			string_case("h3") : { return ht_id_tag_h3; break; }
			string_case("h4") : { return ht_id_tag_h4; break; }
			string_case("h5") : { return ht_id_tag_h5; break; }
			string_case("h6") : { return ht_id_tag_h6; break; }
			string_case("head") : { return ht_id_tag_head; break; }
			string_case("header") : { return ht_id_tag_header; break; }
			string_case("hgroup") : { return ht_id_tag_hgroup; break; }
			string_case("hr") : { return ht_id_tag_hr; break; }
			string_case("html") : { return ht_id_tag_html; break; }
			string_case("i") : { return ht_id_tag_i; break; }
			string_case("iframe") : { return ht_id_tag_iframe; break; }
			string_case("img") : { return ht_id_tag_img; break; }
			string_case("input") : { return ht_id_tag_input; break; }
			string_case("ins") : { return ht_id_tag_ins; break; }
			string_case("kbd") : { return ht_id_tag_kbd; break; }
			string_case("label") : { return ht_id_tag_label; break; }
			string_case("legend") : { return ht_id_tag_legend; break; }
			string_case("li") : { return ht_id_tag_li; break; }
			string_case("link") : { return ht_id_tag_link; break; }
			string_case("map") : { return ht_id_tag_map; break; }
			string_case("mark") : { return ht_id_tag_mark; break; }
			string_case("menu") : { return ht_id_tag_menu; break; }
			string_case("meta") : { return ht_id_tag_meta; break; }
			string_case("meter") : { return ht_id_tag_meter; break; }
			string_case("nav") : { return ht_id_tag_nav; break; }
			string_case("noscript") : { return ht_id_tag_noscript; break; }
			string_case("object") : { return ht_id_tag_object; break; }
			string_case("ol") : { return ht_id_tag_ol; break; }
			string_case("optgroup") : { return ht_id_tag_optgroup; break; }
			string_case("option") : { return ht_id_tag_option; break; }
			string_case("output") : { return ht_id_tag_output; break; }
			string_case("p") : { return ht_id_tag_p; break; }
			string_case("param") : { return ht_id_tag_param; break; }
			string_case("pre") : { return ht_id_tag_pre; break; }
			string_case("progress") : { return ht_id_tag_progress; break; }
			string_case("q") : { return ht_id_tag_q; break; }
			string_case("rp") : { return ht_id_tag_rp; break; }
			string_case("rt") : { return ht_id_tag_rt; break; }
			string_case("ruby") : { return ht_id_tag_ruby; break; }
			string_case("s") : { return ht_id_tag_s; break; }
			string_case("samp") : { return ht_id_tag_samp; break; }
			string_case("script") : { return ht_id_tag_script; break; }
			string_case("section") : { return ht_id_tag_section; break; }
			string_case("select") : { return ht_id_tag_select; break; }
			string_case("small") : { return ht_id_tag_small; break; }
			string_case("source") : { return ht_id_tag_source; break; }
			string_case("span") : { return ht_id_tag_span; break; }
			string_case("strike") : { return ht_id_tag_strike; break; }
			string_case("strong") : { return ht_id_tag_strong; break; }
			string_case("style") : { return ht_id_tag_style; break; }
			string_case("sub") : { return ht_id_tag_sub; break; }
			string_case("summary") : { return ht_id_tag_summary; break; }
			string_case("sup") : { return ht_id_tag_sup; break; }
			string_case("table") : { return ht_id_tag_table; break; }
			string_case("tbody") : { return ht_id_tag_tbody; break; }
			string_case("td") : { return ht_id_tag_td; break; }
			string_case("textarea") : { return ht_id_tag_textarea; break; }
			string_case("tfoot") : { return ht_id_tag_tfoot; break; }
			string_case("th") : { return ht_id_tag_th; break; }
			string_case("thead") : { return ht_id_tag_thead; break; }
			string_case("time") : { return ht_id_tag_time; break; }
			string_case("title") : { return ht_id_tag_title; break; }
			string_case("tr") : { return ht_id_tag_tr; break; }
			string_case("track") : { return ht_id_tag_track; break; }
			string_case("u") : { return ht_id_tag_u; break; }
			string_case("ul") : { return ht_id_tag_ul; break; }
			string_case("var") : { return ht_id_tag_var; break; }
			string_case("video") : { return ht_id_tag_video; break; }
			string_case("altglyph") : { return ht_id_tag_altGlyph; break; }
			string_case("tglyphdef") : { return ht_id_tag_altGlyphDef; break; }
			string_case("glyphitem") : { return ht_id_tag_altGlyphItem; break; }
			string_case("animate") : { return ht_id_tag_animate; break; }
			string_case("matecolor") : { return ht_id_tag_animateColor; break; }
			string_case("atemotion") : { return ht_id_tag_animateMotion; break; }
			string_case("transform") : { return ht_id_tag_animateTransform; break; }
			string_case("circle") : { return ht_id_tag_circle; break; }
			string_case("clipPath") : { return ht_id_tag_clipPath; break; }
			string_case("cursor") : { return ht_id_tag_cursor; break; }
			string_case("defs") : { return ht_id_tag_defs; break; }
			string_case("desc") : { return ht_id_tag_desc; break; }
			string_case("discard") : { return ht_id_tag_discard; break; }
			string_case("ellipse") : { return ht_id_tag_ellipse; break; }
			string_case("feblend") : { return ht_id_tag_feBlend; break; }
			string_case("lormatrix") : { return ht_id_tag_feColorMatrix; break; }
			string_case("ttransfer") : { return ht_id_tag_feComponentTransfer; break; }
			string_case("composite") : { return ht_id_tag_feComposite; break; }
			string_case("lvematrix") : { return ht_id_tag_feConvolveMatrix; break; }
			string_case("elighting") : { return ht_id_tag_feDiffuseLighting; break; }
			string_case("cementMap") : { return ht_id_tag_feDisplacementMap; break; }
			string_case("tantlight") : { return ht_id_tag_feDistantLight; break; }
			string_case("feflood") : { return ht_id_tag_feFlood; break; }
			string_case("fefunca") : { return ht_id_tag_feFuncA; break; }
			string_case("fefuncb") : { return ht_id_tag_feFuncB; break; }
			string_case("fefuncg") : { return ht_id_tag_feFuncG; break; }
			string_case("fefuncr") : { return ht_id_tag_feFuncR; break; }
			string_case("ssianblur") : { return ht_id_tag_feGaussianBlur; break; }
			string_case("feimage") : { return ht_id_tag_feImage; break; }
			string_case("femerge") : { return ht_id_tag_feMerge; break; }
			string_case("mergenode") : { return ht_id_tag_feMergeNode; break; }
			string_case("orphology") : { return ht_id_tag_feMorphology; break; }
			string_case("feoffset") : { return ht_id_tag_feOffset; break; }
			string_case("ointlight") : { return ht_id_tag_fePointLight; break; }
			string_case("rlighting") : { return ht_id_tag_feSpecularLighting; break; }
			string_case("spotlight") : { return ht_id_tag_feSpotLight; break; }
			string_case("fetile") : { return ht_id_tag_feTile; break; }
			string_case("urbulence") : { return ht_id_tag_feTurbulence; break; }
			string_case("filter") : { return ht_id_tag_filter; break; }
			string_case("font") : { return ht_id_tag_font; break; }
			string_case("ignobject") : { return ht_id_tag_foreignObject; break; }
			string_case("g") : { return ht_id_tag_g; break; }
			string_case("glyph") : { return ht_id_tag_glyph; break; }
			string_case("glyphref") : { return ht_id_tag_glyphRef; break; }
			string_case("hatch") : { return ht_id_tag_hatch; break; }
			string_case("hatchpath") : { return ht_id_tag_hatchpath; break; }
			string_case("hkern") : { return ht_id_tag_hkern; break; }
			string_case("image") : { return ht_id_tag_image; break; }
			string_case("line") : { return ht_id_tag_line; break; }
			string_case("rgradient") : { return ht_id_tag_linearGradient; break; }
			string_case("marker") : { return ht_id_tag_marker; break; }
			string_case("mask") : { return ht_id_tag_mask; break; }
			string_case("mesh") : { return ht_id_tag_mesh; break; }
			string_case("hgradient") : { return ht_id_tag_meshgradient; break; }
			string_case("meshpatch") : { return ht_id_tag_meshpatch; break; }
			string_case("meshrow") : { return ht_id_tag_meshrow; break; }
			string_case("metadata") : { return ht_id_tag_metadata; break; }
			string_case("mpath") : { return ht_id_tag_mpath; break; }
			string_case("path") : { return ht_id_tag_path; break; }
			string_case("pattern") : { return ht_id_tag_pattern; break; }
			string_case("polygon") : { return ht_id_tag_polygon; break; }
			string_case("polyline") : { return ht_id_tag_polyline; break; }
			string_case("lgradient") : { return ht_id_tag_radialGradient; break; }
			string_case("rect") : { return ht_id_tag_rect; break; }
			string_case("set") : { return ht_id_tag_set; break; }
			string_case("olidcolor") : { return ht_id_tag_solidcolor; break; }
			string_case("stop") : { return ht_id_tag_stop; break; }
			string_case("svg") : { return ht_id_tag_svg; break; }
			string_case("switch") : { return ht_id_tag_switch; break; }
			string_case("symbol") : { return ht_id_tag_symbol; break; }
			string_case("text") : { return ht_id_tag_text; break; }
			string_case("textPath") : { return ht_id_tag_textPath; break; }
			string_case("tref") : { return ht_id_tag_tref; break; }
			string_case("tspan") : { return ht_id_tag_tspan; break; }
			string_case("unknown") : { return ht_id_tag_unknown; break; }
			string_case("use") : { return ht_id_tag_use; break; }
			string_case("view") : { return ht_id_tag_view; break; }
			string_case("vkern") : { return ht_id_tag_vkern; break; }

			string_case("!doctype") : { return ht_id_document_type; break; }
			string_case("!--") : { return ht_id_comment; break; }

			default : { return ht_id_tag__undefined; break; }
		}

		return ht_id_tag__undefined;
	}
}
